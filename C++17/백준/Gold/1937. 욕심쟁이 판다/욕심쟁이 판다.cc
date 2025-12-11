#include<iostream>
using namespace std;

const int N = 500;
int m[N][N];
int dp[N][N];
int n;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int dfs(int cx, int cy) {
	if (dp[cx][cy]) return dp[cx][cy];
	dp[cx][cy] = 1;

	for (int i = 0; i < 4; ++i) {
		int nx = cx + dx[i], ny = cy + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < n && m[nx][ny] > m[cx][cy]) {
			dp[cx][cy] = max(dp[cx][cy], dfs(nx, ny) + 1);
		}
	}
	return dp[cx][cy];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans = max(ans, dfs(i, j));
		}
	}

	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < n; ++j) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << ans;
}