#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int D = 2001;
bool decimal[D];

const int N = 50;
int n;
vector<int> L, R;

bool dfs(int cn, vector<int>& match, vector<int>& v, const vector<vector<int>>& edges, int t, int p) {
	for (int nn : edges[cn]) {
		if (nn == p) continue;
		if (match[nn] == -1) {
			match[nn] = cn;
			return true;
		}
	}

	for (int nn : edges[cn]) {
		if (nn == p) continue;
		if (v[nn] == t) continue;
		v[nn] = t;
		if (dfs(match[nn], match, v, edges, t, p)) {
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

	decimal[1] = true;
	for (int i = 2; i * i < D; ++i) {
		for (int j = i * i; j < D; j += i) {
			decimal[j] = true;
		}
	}

	cin >> n;
	int fst = -1;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		if (!i) fst = a;
		if (a % 2) R.push_back(a);
		else L.push_back(a);
	}

	if (R.size() != L.size()) {
		cout << -1;
		return 0;
	}

	int m = L.size();
	vector<vector<int>> edges(m);
	if (fst % 2) swap(R, L);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (decimal[L[i] + R[j]]) continue;
			edges[i].push_back(j);
		}
	}
	
	if (edges[0].empty()) {
		cout << -1;
		return 0;
	}

	vector<int> ans;
	for (int nn : edges[0]) {
		vector<int> match(m, -1);
		vector<int> v(m, 0);
		int t = 0;

		int cnt = 0;
		for (int i = 1; i < m; ++i) {
			if (dfs(i, match, v, edges, ++t, nn)) cnt++;
		}
		if (cnt == m - 1) ans.push_back(R[nn]);
	}

	if (ans.empty()) {
		cout << -1;
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (int i : ans) cout << i << " ";
}