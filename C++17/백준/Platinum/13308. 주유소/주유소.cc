#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 2501;
int n, m;
int p[N];
struct Edge {
	int nn, nv;
	bool operator<(const Edge& other) const {
		return nv < other.nv;
	}
};
vector<Edge> edges[N];
struct Pos {
	int cn, cf;
	ll cc;
	bool operator<(const Pos& other) const {
		return cc > other.cc;
	}
};

ll dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 1, p[1], 0 });
	vector<vector<ll>> dist(n + 1, vector<ll>(N, 1e11));
	dist[1][p[1]] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cf = pos.cf;
		ll cc = pos.cc;
		//cout << cn << " " << cf << " " << cc << "\n";
		if (cn == n) return cc;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn;
			int nf = min(cf, p[nn]);
			ll nc = cc + cf * edge.nv;

			if (dist[nn][nf] > nc) {
				dist[nn][nf] = nc;
				pq.push({ nn, nf, nc });
			}
		}
	}

	ll ans = 1e11;
	for (int i = 1; i <= N; ++i) ans = min(ans, dist[n][i]);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; ++i) sort(edges[i].begin(), edges[i].end());

	cout << dijkstra();
}