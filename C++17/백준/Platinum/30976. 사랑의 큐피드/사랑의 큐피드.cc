#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

const int N = 401;
int n, m;
int wh[N], mh[N];
int lh[N], uh[N];
vector<int> edges[N];
int match[N];
int v[N];
int t;

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
	for (int i = 1; i <= n; ++i) cin >> wh[i];
	for (int i = 1; i <= m; ++i) cin >> mh[i];
	for (int i = 1; i <= n; ++i) cin >> lh[i];
	for (int i = 1; i <= m; ++i) cin >> uh[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (lh[i] > mh[j] && wh[i] > uh[j]) edges[i].push_back(j);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfs(i)) ans++;
	}
	cout << ans;
}