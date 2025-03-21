#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define pii pair<int, int>
using namespace std;

int k, n, r;
struct Edge {
	int nn, l, t;
};
vector<Edge> edges[101];
struct Pos {
	int cn, cl, ct;
	bool operator<(const Pos& other) const {
		if (cl == other.cl) return ct > other.ct;
		return cl > other.cl;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 1, 0, 0 });
	vector<vector<pii>> best(n + 1);
	best[1].push_back({ 0, 0 });

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cl = pos.cl, ct = pos.ct;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nl = cl + edge.l, nt = ct + edge.t;

			if (nt > k) continue;
			bool flag = false;
			for (auto it = best[nn].begin(); it != best[nn].end();) {
				if ((*it).first <= nl && (*it).second <= nt) {
					flag = true;
					break;
				}
				else if ((*it).first > nl && (*it).second > nt) {
					it = best[nn].erase(it);
				}
				else it++;
			}
			if (!flag) {
				best[nn].push_back({ nl, nt });
				pq.push({ nn, nl, nt });
			}
		}
	}
	sort(best[n].begin(), best[n].end());
	return best[n].empty() ? -1 : best[n][0].first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n >> r;
	while (r--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		edges[a].push_back({ b, c, d });
	}

	cout << dijkstra();
}