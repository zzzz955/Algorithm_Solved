#include<iostream>
#include<queue>
#include<vector>
#define ll long long
using namespace std;

const int N = 4001;
int n, m;
struct Edge {
	int nn, nv;
};
vector<Edge> edges[N];
struct Fox {
	int cn;
	ll cv;
	bool operator<(const Fox& other) const {
		return cv > other.cv;
	}
};
struct Wolf {
	int cn;
	ll cv;
	bool cf;
	bool operator<(const Wolf& other) const {
		return cv > other.cv;
	}
};

vector<ll> dijkstra_fox() {
	priority_queue<Fox> pq;
	pq.push({ 1, 0 });
	vector<ll> dist(n + 1, 1e18);
	dist[1] = 0;

	while (!pq.empty()) {
		Fox fox = pq.top(); pq.pop();
		int cn = fox.cn;
		ll cv = fox.cv;
		if (dist[cn] < cv) continue;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn;
			ll nv = cv + edge.nv;

			if (dist[nn] > nv) {
				dist[nn] = nv;
				pq.push({ nn, nv });
			}
		}
	}
	return dist;
}
vector<ll> dijkstra_wolf() {
	priority_queue<Wolf> pq;
	pq.push({ 1, 0, false });
	vector<vector<ll>> dist(n + 1, vector<ll>(2, 1e18));
	dist[1][0] = 0;

	while (!pq.empty()) {
		Wolf wolf = pq.top(); pq.pop();
		int cn = wolf.cn;
		ll cv = wolf.cv;
		bool cf = wolf.cf;
		if (dist[cn][cf] < cv) continue;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn;
			ll nv = cf ? cv + edge.nv * 2 : cv + edge.nv / 2;
			bool nf = cf ^ true;

			if (dist[nn][nf] > nv) {
				dist[nn][nf] = nv;
				pq.push({ nn, nv, nf });
			}
		}
	}
	vector<ll> res(n + 1);
	for (int i = 1; i <= n; ++i) {
		res[i] = min(dist[i][0], dist[i][1]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c * 2 });
		edges[b].push_back({ a, c * 2 });
	}

	vector<ll> dist_fox = dijkstra_fox();
	vector<ll> dist_wolf = dijkstra_wolf();
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		//cout << "fox : " << dist_fox[i] << " wolf : " << dist_wolf[i] << "\n";
		if (dist_fox[i] < dist_wolf[i]) ans++;
	}
	cout << ans;
}