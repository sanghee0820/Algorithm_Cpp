#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compair(pair<int, int> a, pair<int,int> b){
    if( a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main(){
    int N, K;
    vector<pair<int,int>> Goods;
    int DP[101][100001];

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        Goods.push_back(make_pair(temp1, temp2));
    }
    for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			 
			 if (j - Goods[i-1].first >= 0) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - Goods[i-1].first + Goods[i-1].second]);
			 else DP[i][j] = DP[i - 1][j];
		}
	}

    cout << DP[N][K];

    return 0;
}