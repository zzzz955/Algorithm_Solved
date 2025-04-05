#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int V = 5001;
int v, e, p;
struct Edge {
	int nn, nv;
};
vector<Edge> edges[V];
struct Pos {
	int cn, cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

int dijkstra(int sn, int dn) {
	priority_queue<Pos> pq;
	pq.push({ sn, 0 });
	vector<int> dist(v + 1, 2e9);
	dist[sn] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;
		if (cn == dn) return dist[cn];
		if (dist[cn] < cv) continue;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = edge.nv;
			if (dist[nn] > cv + nv) {
				dist[nn] = cv + nv;
				pq.push({ nn, dist[nn] });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> p;
	while (e--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	int fast = dijkstra(1, v);
	if (fast == dijkstra(1, p) + dijkstra(p, v)) cout << "SAVE HIM";
	else cout << "GOOD BYE";
}