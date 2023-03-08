#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int Test_cnt, N;

    cin >> Test_cnt;

    vector<int> dp;
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(4);

    for(int i = 3; i < 11; i++){
        dp.push_back(dp[i-1] + dp[i-2] + dp[i-3] );
    }

    for(int i = 0; i < Test_cnt; i++){
        cin >> N;
        cout << dp[N-1] << "\n";
    }
    return 0;
}