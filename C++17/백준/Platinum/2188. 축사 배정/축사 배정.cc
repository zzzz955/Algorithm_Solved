#include<iostream>
#include<vector>
using namespace std;

const int N = 201;
const int M = 201;
int n, m, c, j, ans;
vector<int> edges[N];
int mat[M];
int v[M];
int t;

bool dfs(int node) {
	if (v[node] == t) return false;
	v[node] = t;
	for (int next : edges[node]) {
		//if (v[next] == t) continue;
		//v[next] = t;

		if (!mat[next]) {
			mat[next] = node;
			return true;
		}
	}

	for (int next : edges[node]) {
		//if (v[next] == t) continue;
		//v[next] = t;

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
		if (ans == m) break;
	}
	cout << ans;
}