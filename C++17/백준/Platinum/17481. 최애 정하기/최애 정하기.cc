#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

const int N = 1001;
const int M = 1001;
int n, m, c, ans;
string name;
unordered_map<string, int> idx;
vector<int> edges[N];
int mat[M];
int v[M];
int t;

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
	for (int i = 1; i <= m; ++i) {
		cin >> name;
		idx[name] = i;
	}

	for (int i = 1; i <= n; ++i) {
		cin >> c;
		while (c--) {
			cin >> name;
			edges[i].push_back(idx[name]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfs(i)) ans++;
	}
	
	if (ans == n) cout << "YES";
	else cout << "NO\n" << ans;
}