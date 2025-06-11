#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e5 + 1;
int n, m, a, b, c;
struct Edge {
	int nn, nv;
};
vector<Edge> edges[N];
struct Pos {
	int cn, cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

vector<int> dijkstra(int sn) {
	priority_queue<Pos> pq;
	pq.push({ sn, 0 });
	vector<int> dist(n + 1, 2e9);
	dist[sn] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = edge.nv;

			if (dist[nn] > cv + nv) {
				dist[nn] = cv + nv;
				pq.push({ nn, cv + nv });
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> c >> m;
	while (m--) {
		int d, e, l; cin >> d >> e >> l;
		edges[d].push_back({ e, l });
		edges[e].push_back({ d, l });
	}

	vector<int> a_dist = dijkstra(a);
	vector<int> b_dist = dijkstra(b);
	vector<int> c_dist = dijkstra(c);

	int dist = 0;
	int node = 0;
	for (int i = 1; i <= n; ++i) {
		int min_dist = min({ a_dist[i], b_dist[i], c_dist[i] });
		if (dist < min_dist) {
			dist = min_dist;
			node = i;
		}
	}
	cout << node;
}