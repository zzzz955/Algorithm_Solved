#include<iostream>
#include<vector>
using namespace std;

const int N = 101;
const int M = 5001;
int n, m, ans;
int mat[M];
int v[M];
int t;
vector<int> edges[N];

bool dfs(int node) {
	if (v[node] == t) return false;
	v[node] = t;
	
	for (int next : edges[node]) {
		if (!mat[next]) {
			mat[next] = node;
			return true;
		}
	}

	for (int next : edges[node]) {
		if (dfs(mat[next])) {
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
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfs(i)) ans++;
	}
	cout << ans;
}