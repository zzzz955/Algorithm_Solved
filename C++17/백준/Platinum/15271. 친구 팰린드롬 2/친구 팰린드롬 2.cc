#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 201;
int n, m;
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
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int a, b; cin >> a >> b;
		if ((a + b) % 2 == 0) continue;
		if (b % 2) swap(a, b);
		edges[a].push_back(b);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i += 2) {
		t++;
		if (dfs(i)) cnt++;
	}
	cout << min(n, 2 * cnt + 1);
}