#include <iostream>
#include <vector>
using namespace std;


int answer = 0;

vector<int> Queen;

bool Check(int Cnt){
    for (int i = 0; i < Cnt; i++)
        if ( Queen[Cnt] == Queen[i] || Cnt - i == abs(Queen[Cnt] - Queen[i]) ) return 0;   // Same col || Same diagonal

    return 1;
}

void N_Queen(int Cnt, int N){
    if (Cnt == N){
        answer++;
        return;
    }

    for (int j = 0; j < N; j++){
        Queen[Cnt] = j;
        if (Check(Cnt)) N_Queen(Cnt + 1, N);
    }
}

int main(){
    int N;

    cin >> N;
    Queen.resize(N);

    N_Queen(0, N);
    cout << answer;
}