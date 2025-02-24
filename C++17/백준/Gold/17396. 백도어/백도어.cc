#include<iostream>
#include<vector>
#include<queue>
#define ll long long
using namespace std;

const int N = 100000;
int n, m;
int lst[N];
struct Edge {
	int nn;
	ll nt;
};
vector<Edge> edges[N];
struct Pos {
	int cn;
	ll ct;
	bool operator<(const Pos& other) const {
		return ct > other.ct;
	}
};

ll dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0 });
	vector<ll> dist(n, 1e15);
	dist[0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn;
		ll ct = pos.ct;
		if (dist[cn] < ct) continue;
		if (cn == n - 1) return ct;
		
		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn;
			ll nt = edge.nt;
			if (lst[nn] && nn != n - 1) continue;
			if (dist[nn] > ct + nt) {
				dist[nn] = ct + nt;
				pq.push({ nn, ct + nt });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	while (m--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	cout << dijkstra();
}