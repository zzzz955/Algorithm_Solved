#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e3;
unordered_map<int, int> vi;
vector<int> iv;
vector<int> edges[N];
int n, m;
vector<int> v;
vector<int> match;
int t;

bool dfs(int cn) {
	for (int nn : edges[cn]) {
		if (match[nn] == -1) {
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

	while (1) {
		cin >> n;
		if (!n) break;

		cin >> m;
		vi.clear();
		iv.clear();
		v.clear();
		match.clear();
		t = 0;

		for (int i = 0; i < m; ++i) {
			int d; cin >> d;
			iv.push_back(d);
		}
		sort(iv.begin(), iv.end());
		iv.erase(unique(iv.begin(), iv.end()), iv.end());
		m = iv.size();
		v.resize(m, 0);
		match.resize(m, -1);
		
		for (int i = 0; i < m; ++i) vi[iv[i]] = i;		

		for (int i = 0; i < n; ++i) {
			int c; cin >> c;
			edges[i].clear();

			vector<int> edge;
			while (c--) {
				int d; cin >> d;
				if (!vi.count(d)) continue;

				int idx = vi[d];
				edge.push_back(idx);
			}
			sort(edge.begin(), edge.end());
			edge.erase(unique(edge.begin(), edge.end()), edge.end());
			edges[i] = edge;
		}

		int ans = 0;
		for (int i = 0; i < n; ++i, ++t) {
			if (dfs(i)) ++ans;
		}
		cout << ans << "\n";
	}
}