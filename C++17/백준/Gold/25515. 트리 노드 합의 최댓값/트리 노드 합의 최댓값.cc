#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int N = 1e5;
int w[N];
ll dp[N];
int n;
vector<int> edges[N];

ll dfs(int cn) {
	if (edges[cn].empty()) return w[cn];
	dp[cn] = w[cn];

	for (int nn : edges[cn]) {
		dp[cn] = max(dp[cn], dp[cn] + dfs(nn));
	}

	return dp[cn];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p, c; cin >> p >> c;
		edges[p].push_back(c);
	}

	for (int i = 0; i < n; ++i) cin >> w[i];

	cout << dfs(0);
}