#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1e3 + 1;
int n, m;
struct Edge {
	int y, z;
};
vector<Edge> edges[N];
struct Pos {
	int x, v;
	bool operator<(const Pos& other) const {
		return v > other.v;
	}
};
struct Path {
	int f, t;
};

vector<Path> get_path() {
	priority_queue<Pos> pq;
	pq.push({ 1, 0 });
	vector<int> dist(n + 1, 2e9);
	dist[1] = 0;
	vector<int> prev(n + 1);

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cv = pos.v;
		if (dist[cx] < cv) continue;
		if (cx == n) break;

		for (const Edge& edge : edges[cx]) {
			int nx = edge.y, nv = cv + edge.z;

			if (dist[nx] > nv) {
				dist[nx] = nv;
				prev[nx] = cx;
				pq.push({ nx, nv });
			}
		}
	}

	vector<Path> paths;
	int cur = n;
	while (cur != 1) {
		paths.push_back({prev[cur], cur});
		cur = prev[cur];
	}
	return paths;
}

int dijkstra(int f, int t) {
	priority_queue<Pos> pq;
	pq.push({ 1, 0 });
	vector<int> dist(n + 1, 2e9);
	dist[1] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cv = pos.v;
		if (dist[cx] < cv) continue;
		if (cx == n) return cv;

		for (const Edge& edge : edges[cx]) {
			int nx = edge.y, nv = cv + edge.z;
			if (cx == f && t == nx) continue;
			if (nx == f && t == cx) continue;

			if (dist[nx] > nv) {
				dist[nx] = nv;
				pq.push({ nx, nv });
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
		int x, y, z; cin >> x >> y >> z;
		edges[x].push_back({ y, z });
		edges[y].push_back({ x, z });
	}

	vector<Path> paths = get_path();
	int mx = 0;
	for (const Path& path : paths) {
		int f = path.f, t = path.t;
		mx = max(mx, dijkstra(f, t));
	}
	cout << mx;
}