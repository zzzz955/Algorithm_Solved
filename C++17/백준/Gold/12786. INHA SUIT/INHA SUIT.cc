#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 100;
int n, k;
struct Pos {
	int x, y, t;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};
vector<int> hole[N];

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 1, 0 });
	vector<vector<int>> dist(n + 1, vector<int>(21, 2e9));
	dist[0][1] = 0;
	
	while (!pq.empty()) {
		auto [cx, cy, ct] = pq.top(); pq.pop();

		if (cx == n) continue;
		if (dist[cx][cy] < ct) continue;

		for (int ny : hole[cx]) {
			if (cy == ny && dist[cx + 1][ny] > ct) {
				dist[cx + 1][ny] = ct;
				pq.push({ cx + 1, ny, ct });
			}

			if (cy + 1 == ny && dist[cx + 1][ny] > ct) {
				dist[cx + 1][ny] = ct;
				pq.push({ cx + 1, ny, ct });
			}

			if (cy - 1 == ny && dist[cx + 1][ny] > ct) {
				dist[cx + 1][ny] = ct;
				pq.push({ cx + 1, ny, ct });
			}

			if ((cy * 2 > 20 ? 20 : cy * 2) == ny && dist[cx + 1][ny] > ct) {
				dist[cx + 1][ny] = ct;
				pq.push({ cx + 1, ny, ct });
			}

			if (ct < k && dist[cx + 1][ny] > ct + 1) {
				dist[cx + 1][ny] = ct + 1;
				pq.push({ cx + 1, ny, ct + 1 });
			}
		}
	}

	int mn = 2e9;
	for (int i = 1; i < 21; ++i) {
		mn = min(mn, dist[n][i]);
	}
	return mn;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int m; cin >> m;

		while (m--) {
			int h; cin >> h;
			hole[i].push_back(h);
		}
	}

	int ans = dijkstra();
	cout << (ans == 2e9 ? -1 : ans);
}