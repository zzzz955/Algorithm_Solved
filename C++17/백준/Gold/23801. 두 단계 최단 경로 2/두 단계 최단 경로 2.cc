#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;
using ll = long long;

const int N = 1e5 + 1;
int n, m, p, x, z;
struct Edge {
	int nn, w;
};
vector<Edge> edges[N];
unordered_set<int> dic;
struct Pos {
	int cn;
	ll ct;
	bool flag;
	bool operator<(const Pos& other) const {
		return ct > other.ct;
	}
};

ll dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ x, 0, false });
	vector<vector<ll>> dist(n + 1, vector<ll>(2, 1e18));
	dist[x][0] = 0;

	while (!pq.empty()) {
		auto [cn, ct, cf] = pq.top(); pq.pop();

		if (dist[cn][cf] < ct) continue;
		if (cn == z && cf == true) return dist[cn][cf];

		for (const Edge& edge : edges[cn]) {
			auto [nn, w] = edge;

			ll nt = ct + w;
			bool nf = dic.count(nn) ? true : cf;
			if (dist[nn][nf] > nt) {
				dist[nn][nf] = nt;
				pq.push({ nn, nt, nf });
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int f, t, w; cin >> f >> t >> w;
		edges[f].push_back({ t, w });
		edges[t].push_back({ f, w });
	}

	cin >> x >> z >> p;
	while (p--) {
		int y; cin >> y;
		dic.insert(y);
	}

	cout << dijkstra();
}