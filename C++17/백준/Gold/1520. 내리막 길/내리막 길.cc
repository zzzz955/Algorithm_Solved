#include<iostream>
using namespace std;

int n, m, ans;
int lst[500][500];
bool v[500][500];
int dp[500][500];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	int cur = lst[x][y];

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && lst[nx][ny] < cur) {
			v[nx][ny] = true;
			dp[x][y] += dfs(nx, ny);
			v[nx][ny] = false;
		}
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> lst[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0);
}