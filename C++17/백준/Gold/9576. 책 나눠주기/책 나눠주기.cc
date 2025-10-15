#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1001;
int tc, n, m;
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

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		memset(match, 0, sizeof(match));

		for (int i = 1; i <= m; ++i) {
			edges[i].clear();

			int s, e; cin >> s >> e;
			for (int j = s; j <= e; ++j) {
				edges[i].push_back(j);
			}
		}

		int ans = 0;
		for (int i = 1; i <= m; ++i, ++t) {
			if (dfs(i)) ans++;
		}
		cout << ans << "\n";
	}
}