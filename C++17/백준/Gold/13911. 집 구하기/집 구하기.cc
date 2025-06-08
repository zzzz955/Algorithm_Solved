#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1e4 + 1;
int v, e;
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

void dijkstra(priority_queue<Pos>& pq, vector<int>& dist, int limit) {
	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = edge.nv;
			if (cv + nv > limit) continue;

			if (dist[nn] > cv + nv) {
				dist[nn] = cv + nv;
				pq.push({ nn, cv + nv });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	priority_queue<Pos> mc;
	priority_queue<Pos> sb;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	int m, x; cin >> m >> x;
	vector<int> m_dist(v + 1, 2e9);
	while (m--) {
		int a; cin >> a;
		mc.push({ a, 0 });
		m_dist[a] = 0;
	}
	dijkstra(mc, m_dist, x);

	int s, y; cin >> s >> y;
	vector<int> s_dist(v + 1, 2e9);
	while (s--) {
		int a; cin >> a;
		sb.push({ a, 0 });
		s_dist[a] = 0;
	}
	dijkstra(sb, s_dist, y);
	
	int ans = 2e9;
	for (int i = 1; i <= v; ++i) {
		if (!m_dist[i] || !s_dist[i] || m_dist[i] == 2e9 || s_dist[i] == 2e9) continue;
		ans = min(ans, m_dist[i] + s_dist[i]);
	}
	if (ans != 2e9) cout << ans;
	else cout << -1;
}