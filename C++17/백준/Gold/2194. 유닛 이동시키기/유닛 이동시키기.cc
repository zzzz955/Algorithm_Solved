#include<iostream>
#include<queue>
using namespace std;

int n, m, a, b, k;
bool lst[501][501];
bool v[501][501];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y, t;
};

int bfs(int sx, int sy, int ex, int ey) {
	queue<Pos> q;
	q.push({ sx, sy, 0 });
	v[sx][sy] = true;
	
	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;
		if (cx == ex && cy == ey) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
			if (0 < nx && nx + a - 1 <= n && 0 < ny && ny + b - 1 <= m && !v[nx][ny]) {
				v[nx][ny] = true;
				bool move = true;

				if (i == 0) {
					for (int j = 0; j < b; ++j) {
						if (lst[nx + a - 1][ny + j]) {
							move = false;
							break;
						}
					}
				}
				else if (i == 1) {
					for (int j = 0; j < b; ++j) {
						if (lst[nx][ny + j]) {
							move = false;
							break;
						}
					}
				}
				else if (i == 2) {
					for (int j = 0; j < a; ++j) {
						if (lst[nx + j][ny + b - 1]) {
							move = false;
							break;
						}
					}
				}
				else {
					for (int j = 0; j < a; ++j) {
						if (lst[nx + j][ny]) {
							move = false;
							break;
						}
					}
				}

				if (move) {
					q.push({ nx, ny, nt });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> a >> b >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		lst[x][y] = true;
	}

	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	cout << bfs(sx, sy, ex, ey);
}