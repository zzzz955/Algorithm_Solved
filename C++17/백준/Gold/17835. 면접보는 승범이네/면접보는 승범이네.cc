#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 100001;
int n, m, k;
int K[N];
struct Edge {
	int nn;
	ll nv;
};
vector<Edge> edges[N];
struct P {
	int cn;
	ll cv;
	bool operator<(const P& other) const {
		return cv > other.cv;
	}
};

pair<int, ll> dijkstra() {
	priority_queue<P> pq;
	vector<ll> dist(n + 1, 1e11);
	for (int i = 0; i < k; ++i) {
		pq.push({ K[i], 0 });
		dist[K[i]] = 0;
	}

	while (!pq.empty()) {
		P p = pq.top(); pq.pop();
		int cn = p.cn;
		ll cv = p.cv;
		if (dist[cn] < cv) continue;

		for (const Edge& next : edges[cn]) {
			int nn = next.nn;
			ll nv = next.nv;
			
			if (dist[nn] > cv + nv) {
				dist[nn] = cv + nv;
				pq.push({ nn, cv + nv });
			}
		}
	}
	auto it = max_element(dist.begin() + 1, dist.end());
	return { it - dist.begin(), *it };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[b].push_back({ a, c });
	}

	for (int i = 0; i < k; ++i) cin >> K[i];
	auto res = dijkstra();
	cout << res.first << "\n" << res.second;
}