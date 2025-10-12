#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

const int N = 1e5 + 1;
int n, m, a, b;
ll c;
struct Edge {
	int nn, nv;
};
vector<Edge> edges[N];
struct Pos {
	int cn;
	ll cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

bool dijkstra(int limit) {
	priority_queue<Pos> pq;
	pq.push({ a, 0 });
	vector<ll> dist(n + 1, 1e15);
	dist[a] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn;
		ll cv = pos.cv;
		if (cv > dist[cn]) continue;
		if (cn == b) return true;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = edge.nv;

			if (nv > limit) continue;
			if (cv + nv > c) continue;
			if (dist[nn] <= cv + nv) continue;
			dist[nn] = cv + nv;
			pq.push({ nn, cv + nv });
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> a >> b >> c;
	int mc = 0;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (mc < c) mc = c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	int ans = -1, l = 1, r = mc;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (dijkstra(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}