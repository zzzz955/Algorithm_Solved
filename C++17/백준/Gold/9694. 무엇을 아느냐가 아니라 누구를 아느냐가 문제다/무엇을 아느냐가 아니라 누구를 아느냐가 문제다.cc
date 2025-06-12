#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int t, n, m;
struct Edge {
	int nn, nv;
};
struct Pos {
	int cn, cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

vector<int> dijkstra(const vector<vector<Edge>>& edges) {
	priority_queue<Pos> pq;
	pq.push({ m - 1, 0 });
	vector<int> dist(m, 2e9);
	vector<int> path(m);
	dist[m - 1] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;
		//cout << cn << "\n";

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = edge.nv;

			if (dist[nn] > cv + nv) {
				dist[nn] = cv + nv;
				path[nn] = cn;
				pq.push({ nn, cv + nv });
			}
		}
	}

	if (dist[0] == 2e9) return {};

	vector<int> paths;
	int cn = 0;
	while (cn != m - 1) {
		paths.push_back(cn);
		cn = path[cn];
	}
	paths.push_back(m - 1);
	return paths;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n >> m;

		vector<vector<Edge>> edges(m);
		while (n--) {
			int a, b, c; cin >> a >> b >> c;
			edges[a].push_back({ b, c });
			edges[b].push_back({ a, c });
		}

		vector<int> paths = dijkstra(edges);
		//for (int i : paths) cout << i << " ";
		//cout << "\n";
		if (paths.empty()) cout << "Case #" << tc << ": -1";
		else {
			cout << "Case #" << tc << ":";
			for (int i : paths) cout << " " << i;
			cout << "\n";
		}
	}
}