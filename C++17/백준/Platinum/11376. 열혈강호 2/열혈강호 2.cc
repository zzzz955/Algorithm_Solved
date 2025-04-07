#include<iostream>
#include<vector>
using namespace std;

const int N = 1001;
const int M = 1001;
int n, m, c, j, ans;
vector<int> edges[N];
int match[M];
int v[M];
int t;

bool dfs(int node) {
	for (int next : edges[node]) {
		if (v[next] == t) continue;
		v[next] = t;
		if (!match[next] || dfs(match[next])) {
			match[next] = node;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c;
		while (c--) {
			cin >> j;
			edges[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfs(i)) ans++;
		t++;
		if (dfs(i)) ans++;
	}
	cout << ans;
}