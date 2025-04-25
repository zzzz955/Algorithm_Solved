#include<iostream>
#include<queue>
using namespace std;

int n, m;
int lst[1000][1000];
bool v[1000][1000];
int h, w;
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
		if (cx == ex && cy == ey) {
			//cout << "result = cx:" << cx << " cy:" << cy << " ct:" << ct << "\n";
			return ct;
		}
		//cout << "cx:" << cx << " cy:" << cy << " ct:" << ct << "\n";

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;

			if (0 <= nx && nx + h <= n && 0 <= ny && ny + w <= m && !v[nx][ny]) {
				v[nx][ny] = true;

				bool flag = true;
				if (i == 0) {
					for (int i = 0; i < w; ++i) {
						if (lst[nx + h - 1][ny + i]) {
							flag = false;
							break;
						}
					}
				}
				else if (i == 1) {
					for (int i = 0; i < w; ++i) {
						if (lst[nx][ny + i]) {
							flag = false;
							break;
						}
					}
				}
				else if (i == 2) {
					for (int i = 0; i < h; ++i) {
						if (lst[nx + i][ny + w - 1]) {
							flag = false;
							break;
						}
					}
				}
				else {
					for (int i = 0; i < h; ++i) {
						if (lst[nx + i][ny]) {
							flag = false;
							break;
						}
					}
				}

				if (flag) q.push({ nx, ny, nt });
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
			cin >> lst[i][j];
		}
	}

	int sx, sy, ex, ey;
	cin >> h >> w >> sx >> sy >> ex >> ey;
	cout << bfs(--sx, --sy, --ex, --ey);
}