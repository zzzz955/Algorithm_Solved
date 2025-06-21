#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 1e4 + 1;
int n, m, k;
struct Edge {
	int nn, nv;
	bool operator<(const Edge& other) const {
		return nv < other.nv;
	}
};
vector<Edge> edges[N];
struct Pos {
	int cn, ck;
	ll cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

ll dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 1, 0, 0 });
	vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, 1e11));
	dist[1][0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, ck = pos.ck;
		ll cv = pos.cv;
		if (dist[cn][ck] < cv) continue;
		if (cn == n) return cv;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = edge.nv;

			if (dist[nn][ck] > cv + nv) {
				dist[nn][ck] = cv + nv;
				pq.push({ nn, ck, cv + nv });
			}

			int nk = ck + 1;
			if (nk > k) continue;
			if (dist[nn][nk] > cv) {
				dist[nn][nk] = cv;
				pq.push({ nn, nk, cv });
			}
		}
	}

	ll ans = 1e11;
	for (ll i : dist[n]) ans = min(ans, i);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; ++i) sort(edges[i].begin(), edges[i].end());

	cout << dijkstra();
}