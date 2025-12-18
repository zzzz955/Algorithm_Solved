#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

const int N = 1e5 + 1;
int n;
bool v[N];
unordered_set<int> edges[N];
vector<int> path;
int idx;

void dfs(int cn) {
	if (idx + 1 >= n) return;
	v[cn] = true;

	for (int i = 0; i < edges[cn].size(); ++i) {
		if (idx + 1 >= n) break;
		int nn = path[idx + 1];
		if (!edges[cn].count(nn)) continue;
		if (v[nn]) continue;
		++idx;
		dfs(nn);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		edges[a].insert(b);
		edges[b].insert(a);
	}
	
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		path.push_back(a);
	}

	dfs(1);
	cout << (idx == n - 1 ? 1 : 0);
}