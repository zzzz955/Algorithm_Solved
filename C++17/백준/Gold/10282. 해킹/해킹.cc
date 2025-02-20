#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t, n, d, c;
vector<vector<pair<int, int>>> edges;
struct Pos {
	int node, t;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};

pair<int, int> dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ c, 0 });
	vector<int> dist(n + 1, 2e9);
	dist[c] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cur = pos.node, t = pos.t;

		for (auto& next : edges[cur]) {
			if (dist[next.first] > t + next.second) {
				dist[next.first] = t + next.second;
				pq.push({ next.first, t + next.second });
			}
		}
	}

	int max_val = 0;
	int cnt = 0;
	for (int i : dist) {
		if (i != 2e9) {
			cnt++;
			max_val = max(max_val, i);
		}
	}
	return { cnt, max_val };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> d >> c;
		edges.clear();
		edges.resize(n + 1);

		while (d--) {
			int cn, nn, w; cin >> cn >> nn >> w;
			edges[nn].push_back({ cn, w });
		}

		auto ans = dijkstra();
		cout << ans.first << " " << ans.second << "\n";
	}
}