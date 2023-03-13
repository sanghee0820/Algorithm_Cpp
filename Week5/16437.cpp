#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 123457
using namespace std;

bool wolf[MAX];
int island[MAX];
vector<int> v[MAX];

long long DFS(int X) {
	long long temp = 0;

	if (v[X].size() == 0) {
		if (wolf[X])
			return 0;
		else
			return island[X];
	}

	for (int i = 0; i < v[X].size(); i++) {
		temp += DFS(v[X][i]);
	}
	if (wolf[X]) {
		temp -= island[X];
	}
	else
		temp += island[X];

	if (temp < 0)
		return 0;
	else
		return temp;
}

int main() {
    int N, a, p ;
	cin >> N;

	for (int i = 2; i <= N; i++) {
        char animal;
		cin >> animal >> a >> p;
		if (animal == 'W')
			wolf[i] = true;
		island[i] = a;
		v[p].push_back(i);
	}

	cout << DFS(1);

	return 0;
}