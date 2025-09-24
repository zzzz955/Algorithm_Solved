#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int n, m, c, f;
int h, ans;
set<int> w;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> c >> f;
	while (f--) {
		int x, y; cin >> x >> y;
		h = max(h, x);
		w.insert(y);
	}

	int l = h, r = 1e6;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cur = 0;
		int cnt = 0;

		for (int i : w) {
			if (i <= cur) continue;
			cur = i + mid - 1;
			cnt++;
			if (cnt > c) break;
		}
		if (cnt <= c) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}