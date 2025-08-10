#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, s, d;
int vals[500][500];
struct Pos {
	int cn, cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

void first_dijkstra(vector<vector<int>>& edges, vector<vector<int>>& rev) {
	priority_queue<Pos> pq;
	pq.push({ s, 0 });
	vector<int> dist(n, 2e9);
	dist[s] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;
		if (dist[cn] < cv) continue;
		if (cn == d) break;

		for (int nn : edges[cn]) {
			int nv = cv + vals[cn][nn];

			if (dist[nn] > nv) {
				dist[nn] = nv;
				pq.push({ nn, nv });
			}
		}
	}
	if (dist[d] == 2e9) return;

	queue<int> path;
	path.push(d);
	while (!path.empty()) {
		int cn = path.front(); path.pop();
		
		for (int pn : rev[cn]) {
			if (dist[cn] - vals[pn][cn] == dist[pn]) {
				auto it = find(edges[pn].begin(), edges[pn].end(), cn);
				if (it != edges[pn].end()) {
					path.push(pn);
					edges[pn].erase(it);
				}
			}
		}
	}
}

int second_dijkstra(vector<vector<int>>& edges) {
	priority_queue<Pos> pq;
	pq.push({ s, 0 });
	vector<int> dist(n, 2e9);
	dist[s] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv;
		if (dist[cn] < cv) continue;
		if (cn == d) return cv;

		for (int nn : edges[cn]) {
			int nv = cv + vals[cn][nn];

			if (dist[nn] > nv) {
				dist[nn] = nv;
				pq.push({ nn, nv });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n >> m;
		if (!n && !m) break;
		cin >> s >> d;

		vector<vector<int>> edges(n), rev(n);
		while (m--) {
			int cn, nn, v; cin >> cn >> nn >> v;
			vals[cn][nn] = v;
			edges[cn].push_back(nn);
			rev[nn].push_back(cn);
		}
		first_dijkstra(edges, rev);
		cout << second_dijkstra(edges) << "\n";
	}
}