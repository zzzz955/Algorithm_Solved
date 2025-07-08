#include<iostream>
#include<vector>
using namespace std;

const int N = 11;
int n, m, tar, ans;
vector<int> lst[N];

void bt(int cur, int sum, int cnt) {
	if (cnt > ans) return;
	if (sum == tar) {
		ans = min(ans, cnt);
		return;
	}
	if (cur >= m) return;

	int next = cur + 1;
	int nsum = sum;
	for (int i : lst[next]) nsum |= 1 << i - 1;
	bt(next, nsum, cnt + 1);
	bt(next, sum, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int a; cin >> a;
		while (a--) {
			int b; cin >> b;
			lst[i].push_back(b);
		}
	}

	tar = (1 << n) - 1;
	ans = 2e9;
	bt(0, 0, 0);
	if (ans == 2e9) cout << -1;
	else cout << ans;
}