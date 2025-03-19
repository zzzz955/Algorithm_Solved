#include<iostream>
#include<unordered_map>
#include<vector>
#define ll long long
using namespace std;

ll n, m, q;
unordered_map<int, ll> dic;
unordered_map<int, unordered_map<int, int>> lst;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	dic[0] = (n - 2) * (m - 2);
	for (int i = 1; i < 10; ++i) dic[i] = 0;

	while (q--) {
		int x, y; cin >> x >> y;
		lst[x][y] = 1;
		for (int i = x - 2; i <= x; ++i) {
			if (1 <= i && i + 2 <= n) {
				for (int j = y - 2; j <= y; ++j) {
					if (1 <= j && j + 2 <= m) {
						int cnt = 0;
						for (int ii = i; ii <= i + 2; ++ii) {
							for (int jj = j; jj <= j + 2; ++jj) {
								if (lst[ii][jj]) cnt++;
							}
						}
						dic[cnt - 1]--;
						dic[cnt]++;
					}
				}
			}
		}
	}
	vector<ll> ans(10);
	for (const auto& i : dic) ans[i.first] = i.second;
	for (ll i : ans) cout << i << "\n";
}