#include<iostream>
#include<cstring>
using namespace std;

const int N = 10;
int n, m, ans;
int lst[N][N];
int dp[1 << N][N];

int dfs(int mask, int cur) {
	if (mask == (1 << n) - 1) return 0;
	if (dp[mask][cur] != -1) return dp[mask][cur];

	dp[mask][cur] = 2e9;
	for (int i = 0; i < n; ++i) {
		if (!(mask & (1 << i))) {
			dp[mask][cur] = min(dp[mask][cur], lst[cur][i] + dfs(mask | (1 << i), i));
		}
	}
	return dp[mask][cur];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> lst[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				lst[i][j] = min(lst[i][j], lst[i][k] + lst[k][j]);
			}
		}
	}

	cout << dfs(1 << m, m);
}