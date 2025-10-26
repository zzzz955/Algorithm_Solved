#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;

const int N = 1e3;
int n, m;
vector<pii> lst;
int cnt[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int a; cin >> a;
			lst.push_back({ a, i });
		}
	}

	sort(lst.begin(), lst.end());
	int l = 0, c = 0, ans = 1e9;
	for (int r = 0; r < n * m; ++r) {
		if (++cnt[lst[r].second] == 1) ++c;
		while (c == n) {
			//cout << lst[r].first << " " << lst[l].first << " " << ans << "\n";
			ans = min(ans, lst[r].first - lst[l].first);
			if (--cnt[lst[l].second] == 0) --c;
			++l;
		}
	}
	cout << ans;
}