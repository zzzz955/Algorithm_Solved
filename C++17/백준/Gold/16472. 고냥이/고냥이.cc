#include<iostream>
using namespace std;

int n;
string s;
int dic[128];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	int m = s.size();
	int l = 0, r = 0, uniq = 0, ans = 0;
	while (r < m) {
		if (++dic[s[r]] == 1) ++uniq;
		while (uniq > n) {
			if (--dic[s[l++]] == 0) --uniq;
		}

		int len = r - l + 1;
		if (ans < len) ans = len;
		//cout << l << " " << r << " " << uniq << " " << ans << " " << s.substr(l, len) << "\n";
		++r;
	}
	cout << ans;
}