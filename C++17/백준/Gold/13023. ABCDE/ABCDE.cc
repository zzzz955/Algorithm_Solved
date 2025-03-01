#include<iostream>
#include<vector>
using namespace std;

const int N = 2000;
int n, m;
bool ans;
bool v[N];
bool can[N];
vector<int> edges[N];

void dfs(int level, int node) {
	if (level == 5) {
		ans = true;
		return;
	}

	for (int i : edges[node]) {
		if (v[i]) continue;
		v[i] = true;
		dfs(level + 1, i);
		v[i] = false;
	}

	//can[node] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		//if (!can[i]) {
		v[i] = true;
		dfs(1, i);
		v[i] = false;
		//}
		if (ans) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
}