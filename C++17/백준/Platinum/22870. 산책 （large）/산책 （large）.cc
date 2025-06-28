#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 2e5 + 1;
int n, m;
bool v[N];
struct Edge {
	int nn, nv;
	bool operator<(const Edge& other) const {
		return nn < other.nn;
	}
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
		if (dist[cn] < cv) continue;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = cv + edge.nv;

			if (!v[nn] && dist[nn] > nv) {
				dist[nn] = nv;
				pq.push({ nn, nv });
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; ++i) sort(edges[i].begin(), edges[i].end());

	int sn, dn; cin >> sn >> dn;

	vector<int> dist1 = dijkstra(dn);
	int cost = 0, cur = sn;
	while (cur != dn) {
		for (const Edge& edge : edges[cur]) {
			int nn = edge.nn, nv = edge.nv;

			if (cost + dist1[nn] + nv == dist1[sn]) {
				cost += nv;
				cur = nn;
				v[cur] = true;
				break;
			}
		}
	}

	//for (int i = 1; i <= n; ++i) cout << v[i] << " ";
	//cout << "\n";

	v[dn] = false;
	vector<int> dist2 = dijkstra(sn);
	cout << cost + dist2[dn];
}