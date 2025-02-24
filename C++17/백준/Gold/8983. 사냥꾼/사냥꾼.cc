#include<iostream>
#include<algorithm>
using namespace std;

int m, n, l, ans;
int lst[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> l;
	for (int i = 0; i < m; ++i) cin >> lst[i];
	sort(lst, lst + m);

	while (n--) {
		int x, y; cin >> x >> y;
		int L = 0, R = m - 1;
		while (L <= R) {
			int MID = (L + R) / 2;
			int dist = abs(lst[MID] - x) + y;
			if (dist <= l) {
				ans++;
				break;
			}
			else {
				if (x > lst[MID]) L = MID + 1;
				else if (x < lst[MID]) R = MID - 1;
				else break;
			}
		}
	}
	cout << ans;
}