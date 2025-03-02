#include<iostream>
#include<cstring>
using namespace std;

const int N = 16;
int n;
int w[N][N];
int dp[1 << N][N];

int tsp(int mask, int cur) {
	if (mask == (1 << n) - 1) {
		return !w[cur][0] ? 2e9 : w[cur][0];
	}
	if (dp[mask][cur] != -1) return dp[mask][cur];

	dp[mask][cur] = 2e9;
	for (int i = 0; i < n; ++i) {
		if (!w[cur][i]) continue;
		if (!(mask & (1 << i))) {
			dp[mask][cur] = min(dp[mask][cur], w[cur][i] + tsp(mask | (1 << i), i));
		}
	}
	return dp[mask][cur];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> w[i][j];

	memset(dp, -1, sizeof(dp));
	cout << tsp(1, 0);
}