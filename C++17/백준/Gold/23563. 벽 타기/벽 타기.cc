#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, sx, sy, ex, ey;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int lst[500][500];
struct Pos {
	int x, y, t;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ sx, sy, 0 });
	vector<vector<int>> dist(n, vector<int>(m, 2e9));
	dist[sx][sy] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;
		if (dist[cx][cy] < ct) continue;
		if (cx == ex && cy == ey) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !lst[nx][ny]) {
				bool cw = false, nw = false;
				for (int j = 0; j < 4; ++j) {
					int nnx = cx + dx[j], nny = cy + dy[j];
					if (0 <= nnx && nnx < n && 0 <= nny && nny < m && lst[nnx][nny]) {
						cw = true;
						break;
					}
				}

				for (int j = 0; j < 4; ++j) {
					int nnx = nx + dx[j], nny = ny + dy[j];
					if (0 <= nnx && nnx < n && 0 <= nny && nny < m && lst[nnx][nny]) {
						nw = true;
						break;
					}
				}

				int nt = cw && nw ? ct : ct + 1;
				if (dist[nx][ny] > nt) {
					dist[nx][ny] = nt;
					pq.push({ nx, ny, nt });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if (ch == '.') continue;
			else if (ch == '#') lst[i][j] = 1;
			else if (ch == 'S') sx = i, sy = j;
			else if (ch == 'E') ex = i, ey = j;
		}
	}

	cout << dijkstra();
}