#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
pair<int,int> h[50000];
vector<int> stack;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		h[i] = { x, y };
	}
	sort(h, h + n);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int y = h[i].second;
		while (!stack.empty() && stack.back() >= y) {
			if (stack.back() > y) ans++;
			stack.pop_back();
		}
		if (y) stack.push_back(y);
	}
	ans += stack.size();
	cout << ans;
}