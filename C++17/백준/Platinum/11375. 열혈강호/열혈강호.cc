#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1001;
int n, m;
int mat[N];
bool v[N];
vector<int> edges[N];

bool dfs(int node) {
	for (int next : edges[node]) {
		if (v[next]) continue;
		v[next] = true;
		if (!mat[next] || dfs(mat[next])) {
			mat[next] = node;
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
		int j; cin >> j;
		while (j--) {
			int b; cin >> b;
			edges[i].push_back(b);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		memset(v, false, sizeof(v));
		if (dfs(i)) ans++;
	}
	cout << ans << "\n";
}