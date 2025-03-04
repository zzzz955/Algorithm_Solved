#include<iostream>
using namespace std;

int n, k;
struct WV {
	int w, v;
};
WV wvs[101];
int dp[101][100001];

int top_down(int idx, int remain) {
	if (idx > n) return 0;
	if (dp[idx][remain]) return dp[idx][remain];

	int skip = top_down(idx + 1, remain);
	int take = 0;
	if (remain - wvs[idx].w >= 0) take = wvs[idx].v + top_down(idx + 1, remain - wvs[idx].w);

	dp[idx][remain] = max(skip, take);
	return dp[idx][remain];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int w, v; cin >> w >> v;
		wvs[i] = { w, v };
	}
	cout << top_down(1, k);
}