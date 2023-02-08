#include <iostream>
#include <algorithm>
using namespace std;

int check[11] = {0};
int N = 0;
int solution = 100000000;
int v[10][10];


void DFS(int start, int index, int cnt, int sum,int n){
    if(cnt == n){
        if(v[index][start] == 0) return;
        if(solution > sum + v[index][start]) solution = sum + v[index][start];
        return;
    }

    for(int i = 0; i < n; i++){
        if(check[i] || v[index][i] == 0) continue;
        check[i] = 1;
        DFS(start, i, cnt + 1, sum + v[index][i], n);
        check[i] = 0;
    }
}

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        check[i] = true;
        DFS(i,i, 1, 0, n);
        check[i] = 0;
    }

    cout << solution;

    return 0;
}