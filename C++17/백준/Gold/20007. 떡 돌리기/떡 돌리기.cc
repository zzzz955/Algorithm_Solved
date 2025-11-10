#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e3;
int n, m, x, y;
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

vector<int> dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ y, 0 });
	vector<int> dist(n, 2e9);
	dist[y] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;
		if (dist[cn] < cv) continue;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = cv + edge.nv;

			if (dist[nn] > nv) {
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

	cin >> n >> m >> x >> y;
	while (m--) {
		int f, t, v; cin >> f >> t >> v;
		edges[f].push_back({ t, v });
		edges[t].push_back({ f, v });
	}

	vector<int> dist = dijkstra();
	sort(dist.begin(), dist.end());

	int a = 0, s = 0;
	for (int i = 0; i < n; ++i) {
		int d = dist[i] * 2;

		if (d > x) {
			cout << -1;
			return 0;
		}

		if (s + d > x) {
			++a;
			s = d;
		}
		else s += d;

		//cout << a << " " << s << " " << d << "\n";
	}
	if (s) ++a;
	cout << a;
}