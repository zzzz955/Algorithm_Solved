#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, k;
struct Edge {
	int nn, nv;
};
vector<Edge> edges[251];
struct Pos {
	int cn, cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

int dijkstra(int sn, int dn) {
	priority_queue<Pos> pq;
	pq.push({ sn, 0 });
	vector<int> dist(n + 1, 2e9);
	dist[sn] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;

		if (dist[cn] < cv) continue;
		if (cn == dn) return dist[dn];
		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = edge.nv;
			if (dist[nn] > cv + nv) {
				dist[nn] = cv + nv;
				pq.push({ nn, cv + nv });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int u, v, e; cin >> u >> v >> e;
		if (!e) {
			edges[u].push_back({ v, 0 });
			edges[v].push_back({ u, 1 });
		}
		else {
			edges[u].push_back({ v, 0 });
			edges[v].push_back({ u, 0 });
		}
	}
	cin >> k;
	while (k--) {
		int sn, dn; cin >> sn >> dn;
		cout << dijkstra(sn, dn) << "\n";
	}
}