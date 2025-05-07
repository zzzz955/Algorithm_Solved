#include<iostream>
using namespace std;

int t;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> s;
		int l = 0, r = s.size() - 1;
		int ans1 = 0;
		while (l <= r) {
			if (s[l] == s[r]) l++, r--;
			else if (s[l] != s[r]) {
				ans1++;
				if (s[l + 1] == s[r]) l++;
				else ans1++;
			}
			if (ans1 >= 2) break;
		}

		int ans2 = 0;
		l = 0, r = s.size() - 1;
		while (l <= r) {
			if (s[l] == s[r]) l++, r--;
			else if (s[l] != s[r]) {
				ans2++;
				if (s[l] == s[r - 1]) r--;
				else ans2++;
			}
			if (ans2 >= 2) break;
		}

		int res = min(ans1, ans2);
		if (res >= 2) cout << 2 << "\n";
		else cout << res << "\n";
	}
}