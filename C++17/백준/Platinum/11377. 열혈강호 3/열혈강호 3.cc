#include<iostream>
#include<vector>
using namespace std;

const int N = 1001;
const int M = 1001;
int n, m, k, c, j, ans;
vector<int> edges[N];
int match[M];
int v[M];
bool v2[N];
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

	cin >> n >> m >> k;
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

	int add = 0;
	while (add < k) {
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			if (add == k) break;
			if (v2[i]) continue;
			t++;
			if (dfs(i)) {
				v2[i] = true;
				ans++;
				add++;
				flag = true;
			}
			if (ans == m) break;
		}
		if (!flag) break;
	}
	cout << ans;
}