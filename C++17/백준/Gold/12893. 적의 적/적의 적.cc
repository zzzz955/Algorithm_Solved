#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 2001;
int n, m;
int g[N];
vector<int> edges[N];

bool bfs(int sn) {
	queue<int> q;
	q.push(sn);
	g[sn] = 1;

	while (!q.empty()) {
		int cn = q.front(); q.pop();

		for (int nn : edges[cn]) {
			if (g[nn] && g[nn] == g[cn]) return false;
			if (!g[nn]) {
				g[nn] = g[cn] == 1 ? 2 : 1;
				q.push(nn);
			}
		}
	}
	return true;
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

	for (int i = 1; i <= n; ++i) {
		if (g[i]) continue;
		if (!bfs(i)) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}