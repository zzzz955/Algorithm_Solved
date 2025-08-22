#include<iostream>
#include<vector>
using namespace std;
using pii = pair<int, int>;

int n, ans;
vector<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int cur = 0;
	while (n--) {
		char c;  cin >> c;
		//cout << c << " " << cur << " " << (s.empty() ? -1 : s.back()) << "\n";
		if (c == '(') s.push_back(0);
		else {
			if (s.empty()) {
				ans = max(ans, cur);
				cur = 0;
				continue;
			}
			int p = s.back() + 2;
			s.pop_back();
			if (s.empty()) cur += p;
			else s.back() += p;
		}
	}
	ans = max(ans, cur);
	for (int i : s) ans = max(ans, i);
	cout << ans;
}