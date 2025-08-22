#include<iostream>
using namespace std;

const int N = 2e3 + 1;
int n, m;
int lst[N];
bool dp[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> lst[i];
	for (int i = 1; i <= n; ++i) dp[i][i] = true;
	for (int i = 1; i <= n; ++i) dp[i][i + 1] = lst[i] == lst[i + 1];
	for (int i = 3; i <= n; ++i) {
		for (int l = 1; l + i - 1 <= n; ++l) {
			int r = l + i - 1;
			dp[l][r] = lst[l] == lst[r] && dp[l + 1][r - 1];
		}
	}
	cin >> m;
	while (m--) {
		int l, r; cin >> l >> r;
		cout << dp[l][r] << "\n";
	}
}