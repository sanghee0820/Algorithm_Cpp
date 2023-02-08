#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int* Ary;
int* Number;

void DFS(int cnt, int index, int Max_Count, int i){
    if( cnt == Max_Count){
        for(int i = 0; i < cnt; i++){
            cout << Ary[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int j = i; j < index; j++){
        Ary[cnt] = Number[j];
        DFS(cnt + 1, index, Max_Count, j);
    }
}
int main(){
    int N, M;
    cin >> N >> M;

    Ary = (int*)malloc(sizeof(int) * M);
    Number = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        cin >> Number[i];
    }
    sort(Number, Number + N);

    DFS(0, N, M, 0);

    return 0;
}