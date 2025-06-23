#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1001;
int n, m, k, s, d;
struct Edge {
	int nn, nv;
	bool operator<(const Edge& other) const {
		return nv < other.nv;
	}
};
vector<Edge> edges[N];
struct Pos {
	int cn, cc, cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

vector<int> dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ s, 0, 0 });
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 2e9));
	dist[s][0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cc = pos.cc, cv = pos.cv;
		//cout << cn << " " << cc << " " << cv << "\n";

		if (cc >= n) continue;
		if (dist[cn][cc] < cv) continue;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = cv + edge.nv, nc = cc + 1;

			if (dist[nn][nc] > nv) {
				dist[nn][nc] = nv;
				pq.push({ nn, nc, nv });
			}
		}
	}
	//cout << "done\n";

	return dist[d];
}

int tax(vector<int>& dist, int val) {
	int ans = 2e9;
	for (int i = 0; i <= n; ++i) {
		dist[i] += i * val;
		ans = min(ans, dist[i]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k >> s >> d;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; ++i) sort(edges[i].begin(), edges[i].end());

	vector<int> dist = dijkstra();
	cout << tax(dist, 0) << "\n";

	while (k--) {
		int p; cin >> p;
		cout << tax(dist, p) << "\n";
	}
}