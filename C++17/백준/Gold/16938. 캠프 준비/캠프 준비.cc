#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int  n, l, r, x, ans;
int lst[15];
vector<int> c;

void dfs(int level, int sum) {
	if (sum > r) return;
	if (level == n) {
		if (sum < l) return;
		if (!c.empty() && *--c.end() - *c.begin() < x) return;
		ans++;
		return;
	}

	c.push_back(lst[level]);
	dfs(level + 1, sum + lst[level]);
	c.pop_back();
	
	dfs(level + 1, sum);
}

int main() {
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	sort(lst, lst + n);
	dfs(0, 0);
	cout << ans;
}