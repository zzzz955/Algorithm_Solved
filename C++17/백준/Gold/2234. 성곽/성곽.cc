#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 101, M = 101;
bool lst[N][M];
bool v[N][M];
int n, m;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
struct Pos {
	int cx, cy;
};

int floodfill(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = true;
	int area = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.cx, cy = pos.cy;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (1 <= nx && nx < n * 2 && 1 <= ny && ny < m * 2 && !lst[nx][ny]) {
				int nnx = nx + dx[i], nny = ny + dy[i];
				if (v[nnx][nny]) continue;
				v[nnx][nny] = true;
				area++;
				q.push({ nnx, nny });
			}
		}
	}
	return area;
}

void print(bool flag) {
	for (int i = 0; i <= n * 2; ++i) {
		for (int j = 0; j <= m * 2; ++j) {
			cout << (flag ? v[i][j] : lst[i][j]) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int c; cin >> c;
			int cx = 2 * i + 1, cy = 2 * j + 1;
			for (int k = 0; k < 4; ++k) {
				if (c & (1 << k)) {
					int nx = cx + dx[k], ny = cy + dy[k];
					lst[nx][ny] = true;
				}
			}
		}
	}

	//print(false);

	int cnt = 0, max_area = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cx = 2 * i + 1, cy = 2 * j + 1;
			if (!v[cx][cy]) {
				cnt++;
				max_area = max(max_area, floodfill(cx, cy));
			}
		}
	}
	cout << cnt << "\n" << max_area << "\n";

	max_area = 0;
	for (int i = 1; i < n * 2; ++i) {
		for (int j = 1; j < m * 2; ++j) {
			if (lst[i][j]) {
				lst[i][j] = false;
				for (int k = (i % 2 ? 0 : 1); k < 4; k += 2) {
					int sx = i + dx[k], sy = j + dy[k];
					if (1 <= sx && sx < n * 2 && 1 <= sy && sy < m * 2) {
						memset(v, 0, sizeof(v));
						int area = floodfill(sx, sy);
						if (area > max_area) {
							max_area = area;
							//cout << i << " " << j << " " << sx << " " << sy << " " << area << "\n";
							//print(true);
						}
						break;
					}
				}
				lst[i][j] = true;
			}
		}
	}
	cout << max_area;
}