#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int N, K;
int W[101];
int V[101];
int DP[101][100001];
 
void dp(){
    
    for(int i = 1 ; i <= K ; i++){
        for(int j = 1; j <= N; j++){
            //1. 담을 수 없을 경우
            if(W[j] > i){
                DP[j][i] = DP[j-1][i];
            }
            //2. 담을 수 있는 경우
            else{
                DP[j][i] = max(DP[j-1][i - W[j]] + V[j]  ,  DP[j-1][i]);
            }
        }
    }
    
}
 
int main(){
 
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> W[i] >> V[i];
    }
 
    dp();
 
    cout << DP[N][K];
    
    return 0;
}