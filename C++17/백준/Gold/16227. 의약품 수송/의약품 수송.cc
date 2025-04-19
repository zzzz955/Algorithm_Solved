#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1002;
int n, k;
struct Edge {
	int nn, nv;
};
vector<Edge> edges[N];
struct Pos {
	int cn, cv, cs;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, 0 });
	vector<int> dist(n + 2, 2e9);
	dist[0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv, cs = pos.cs;
		if (dist[cn] < cv) continue;
		if (cn == n + 1) return cv;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = cv + edge.nv, ns = cs + edge.nv;
			if (ns > 100) {
				nv += 5;
				ns = edge.nv;
			}

			if (dist[nn] > nv) {
				dist[nn] = nv;
				pq.push({ nn, nv, ns });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	while (k--) {
		int a, b, c; cin >> a >> b >> c;
		if (c > 100) continue;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	cout << dijkstra();
}