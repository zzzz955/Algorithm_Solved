#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> stack;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int ans = 0;
	while (n--) {
		int x, y; cin >> x >> y;
		while (!stack.empty() && stack.back() >= y) {
			if (stack.back() > y) ans++;
			stack.pop_back();
		}
		if (y) stack.push_back(y);
	}
	ans += stack.size();
	cout << ans;
}