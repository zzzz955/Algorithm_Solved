#include<iostream>
#include<vector>
using namespace std;

const int N = 1e3 + 1;
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
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i, ++t) {
		if (dfs(i)) cnt++;
	}
	if (cnt == n) for (int i = 1; i <= n; ++i) cout << match[i] << "\n";
	else cout << "Impossible";
}