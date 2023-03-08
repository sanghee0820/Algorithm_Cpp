#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int N, a, b;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a >> b;
        int result = 1;

        for( int j = 0; j < b; j++) result = result * a % 10;
        if(result == 0) cout << 10 << endl;
        else cout << result << endl;
    }
    return 0;
}