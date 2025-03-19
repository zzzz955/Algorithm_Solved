#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, v, e, a, b;
struct Edge {
	int node, val;
};
vector<Edge> edges[1001];
int lst[100];
int ans;
struct Pos {
	int node, val;
	bool operator<(const Pos& other) const {
		return val > other.val;
	}
};

int dijkstra(int sn) {
	priority_queue<Pos> pq;
	pq.push({ sn, 0 });
	vector<int> dist(v + 1, 2e9);
	dist[sn] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.node, cv = pos.val;
		if (dist[cn] < cv) continue;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.node, nv = edge.val;
			if (dist[nn] > cv + nv) {
				dist[nn] = cv + nv;
				pq.push({ nn, cv + nv });
			}
		}
	}
	if (dist[a] == 2e9) dist[a] = -1;
	if (dist[b] == 2e9) dist[b] = -1;
	return dist[a] + dist[b];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> v >> e >> a >> b;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	while (e--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	for (int i = 0; i < n; ++i) {
		ans += dijkstra(lst[i]);
	}

	cout << ans;
}