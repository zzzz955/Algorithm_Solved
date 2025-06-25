#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 101;
int t, n, m, k;
struct Edge {
	int nn, nc, nd;
	bool operator<(const Edge& other) const {
		return nc < other.nc;
	}
};
struct Pos {
	int cn, cc, cd;
	bool operator<(const Pos& other) const {
		return cd > other.cd;
	}
};

int dijkstra(const vector<vector<Edge>>& edges) {
	priority_queue<Pos> pq;
	pq.push({ 1, 0, 0 });
	vector<vector<int>> dist(n + 1, vector<int>(m + 1, 2e9));
	dist[1][0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cc = pos.cc, cd = pos.cd;

		if (dist[cn][cc] < cd) continue;
		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nc = cc + edge.nc, nd = cd + edge.nd;

			if (nc > m) continue;
			if (dist[nn][nc] > nd) {
				for (int i = nc; i <= m; ++i) {
					if (dist[nn][i] <= nd) break;
					dist[nn][i] = nd;
				}
				pq.push({ nn, nc, nd });
			}
		}
	}

	int res = 2e9;
	for (int i = 0; i <= m; ++i) res = min(res, dist[n][i]);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<vector<Edge>> edges(n + 1);

		while (k--) {
			int u, v, c, d; cin >> u >> v >> c >> d;
			edges[u].push_back({ v, c, d });
		}

		for (int i = 1; i <= n; ++i) sort(edges[i].begin(), edges[i].end());

		int res = dijkstra(edges);
		if (res == 2e9) cout << "Poor KCM\n";
		else cout << res << "\n";
	}
}