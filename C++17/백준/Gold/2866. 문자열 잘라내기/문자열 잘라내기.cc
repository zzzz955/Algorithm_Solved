#include<iostream>
#include<unordered_map>
using namespace std;

int n, m, ans;
string lst[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		unordered_map<string, bool> v;

		bool flag = true;
		for (int j = 0; j < m; ++j) {
			string s = "";
			for (int i = mid; i < n; ++i) {
				s += lst[i][j];
			}
			if (v[s]) {
				flag = false;
				break;
			}
			else v[s] = true;
		}

		if (flag) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}