#include<iostream>
#include<vector>
using namespace std;

int n, ans;
vector<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int d, w; cin >> d >> w;
		bool flag = false;
		while (!s.empty() && w < s.back()) s.pop_back();
		if (s.empty() || s.back() < w) {
			flag = true;
			s.push_back(w);
			ans++;
		}
	}
	cout << ans;
}