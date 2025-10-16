#include<iostream>
#include<vector>
using namespace std;

const int N = 501;
int n, k;
int match[N];
int v[N];
int t;
vector<int> edges[N];

bool dfs(int cn) {
	for (int nn : edges[cn]) {
		if (!match[nn]) {
			match[nn] = cn;
			return true;
		}
	}

	for (int nn : edges[cn]) {
		if (v[nn] == t) continue;
		v[nn] = t;

		if (dfs(match[nn])) {
			match[nn] = cn;
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	while (k--) {
		int r, c; cin >> r >> c;
		edges[r].push_back(c);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i, ++t) {
		if (edges[i].empty()) continue;
		if (dfs(i)) ans++;
	}
	cout << ans;
}