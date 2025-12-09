#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1001;
int n, m;
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

pair<int, vector<pair<int, int>>> f_dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 1, 0 });
	vector<int> dist(n + 1, 2e9);
	vector<int> prev(n + 1, -1);
	dist[1] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;
		if (dist[cn] < cv) continue;
		if (cn == n) break;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = cv + edge.nv;

			if (dist[nn] > nv) {
				dist[nn] = nv;
				prev[nn] = cn;
				pq.push({ nn, nv });
			}
		}
	}

	vector<pair<int, int>> path;
	int cn = n;
	while (cn != 1) {
		path.push_back({ cn, prev[cn] });
		cn = prev[cn];
	}
	return { dist[n], path };
}

int s_dijkstra(int xn1, int xn2) {
	priority_queue<Pos> pq;
	pq.push({ 1, 0 });
	vector<int> dist(n + 1, 2e9);
	dist[1] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;
		if (dist[cn] < cv) continue;
		if (cn == n) return dist[cn];

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = cv + edge.nv;
			if (cn == xn1 && nn == xn2) continue;
			if (cn == xn2 && nn == xn1) continue;

			if (dist[nn] > nv) {
				dist[nn] = nv;
				pq.push({ nn, nv });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b, t; cin >> a >> b >> t;
		edges[a].push_back({ b, t });
		edges[b].push_back({ a, t });
	}

	auto res = f_dijkstra();
	int mx = -1;
	for (const auto& data : res.second) {
		int d = s_dijkstra(data.first, data.second);
		if (d == -1) {
			cout << -1;
			return 0;
		}
		if (mx < d) mx = d;
	}
	cout << mx - res.first;
}