#include<iostream>
#include<vector>
using namespace std;

int n, m, k;
string lst[2000];

int chk(char col) {
	vector<vector<int>> vals(n, vector<int>(m, 0));
	vector<vector<int>> preSums(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((i + j) % 2) vals[i][j] = lst[i][j] == col;
			else vals[i][j] = lst[i][j] != col;
			preSums[i + 1][j + 1] = preSums[i][j + 1] + preSums[i + 1][j] - preSums[i][j] + vals[i][j];
		}
	}

	int ans = 2e9;
	for (int i = 0; i <= n - k; ++i) {
		for (int j = 0; j <= m - k; ++j) {
			ans = min(ans, preSums[i + k][j + k] - preSums[i][j + k] - preSums[i + k][j] + preSums[i][j]);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	cout << min(chk('W'), chk('B'));
}