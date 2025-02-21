#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
struct Edge {
	int next, val;
};
vector<Edge> edges[1001];
struct Info {
	int cur, pre_val;
	bool operator<(const Info& other) const {
		return pre_val > other.pre_val;
	}
};

void dijkstra() {
	priority_queue<Info> pq;
	pq.push({ 1, 0 });
	vector<int> dist(n + 1, 2e9);
	vector<int> path(n + 1, 0);
	dist[1] = 0;

	while (!pq.empty()) {
		Info info = pq.top(); pq.pop();
		int cn = info.cur, cd = info.pre_val;
		if (dist[cn] < cd) continue;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.next, nd = edge.val;
			if (dist[nn] > cd + nd) {
				dist[nn] = cd + nd;
				path[nn] = cn;
				pq.push({ nn, cd + nd });
			}
		}
	}

	cout << n - 1 << "\n";
	for (int i = 2; i <= n; ++i) cout << i << " " << path[i] << "\n";
}

int main() {
	cin >> n >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}
	dijkstra();
}