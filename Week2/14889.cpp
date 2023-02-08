#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int** Human;
int* Team;
int difference = 1000000;


void DFS(int cnt, int N, int i){
    if(cnt == N/2){
        int team1 = 0, team2 = 0;
        for( int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                if(i == j) continue;
                if( (Team[i] == Team[j]) && (Team[j] == 1)){
                    team1 += Human[i][j] + Human[j][i];
                }
                else if ((Team[i] == Team[j]) && (Team[j] == 0)){
                    team2 += Human[i][j] + Human[j][i];
                }
            }
        }

        if( abs(team2-team1) < difference ) difference = abs(team2 - team1);
        return;
    }
    for(int j = i; j < N ; j++){
        Team[j] = 1;
        DFS(cnt + 1, N, j + 1);
        Team[j] = 0;
    }
}
int main(){

    int N;
    cin >> N;
    Human = (int**)malloc(sizeof(int*) * N);
    Team = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        Human[i] = (int*)malloc(sizeof(int) * N);
        for(int j = 0; j < N; j++){
            cin >> Human[i][j];
        }
    }

    DFS(0, N, 0);
    cout << difference;

    return 0;
}