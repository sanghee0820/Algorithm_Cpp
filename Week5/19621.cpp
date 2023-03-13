#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ar;
int result, n;

void dfs(int cnt, int sum) {

	if (cnt > n - 1) {
		result = max(result, sum);
		return;
	}

	dfs(cnt + 1, sum); // 겹치는 회의 
	dfs(cnt + 2, sum + ar[cnt]); // 겹치지 않는 회의
}

int main() {
	cin >> n;
	ar.resize(n);

	for (int i = 0; i < n; i++){
        int trash;
        cin >> trash >> trash;
        cin >> ar[i];
    }
	dfs(0, 0);

	cout << result << endl;

	return 0;
}