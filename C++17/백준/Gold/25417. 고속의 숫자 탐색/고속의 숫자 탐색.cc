#include<iostream>
#include<queue>
using namespace std;

int lst[5][5];
bool v[5][5];
struct Pos {
	int x, y, t;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void print(int x, int y, int t) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (x == i && y == j) cout << 8 << " ";
			else cout << lst[i][j] << " ";
		}
		cout << "\n";
	}
	cout << x << " " << y << " " << t << "\n";
}

int bfs(int sx, int sy) {
	priority_queue<Pos> pq;
	pq.push({ sx, sy, 0 });
	v[sx][sy] = true;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;
		//print(cx, cy, ct);
		if (lst[cx][cy] == 1) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && !v[nx][ny] && lst[nx][ny] != -1) {
				v[nx][ny] = true;
				pq.push({ nx, ny, nt });

				while (1) {
					if (0 > nx || nx >= 5 || 0 > ny || ny >= 5) {
						int nnx = nx - dx[i], nny = ny - dy[i];
						//cout << nx << " " << ny << " " << nnx << " " << nny << "\n";
						if (!v[nnx][nny]) {
							v[nnx][nny] = true;
							pq.push({ nnx, nny, nt });
						}
						break;
					}
					if (lst[nx][ny] == -1) {
						int nnx = nx - dx[i], nny = ny - dy[i];
						if (!v[nnx][nny]) {
							v[nnx][nny] = true;
							pq.push({ nnx, nny, nt });
						}
						break;
					}
					if (lst[nx][ny] == 7) {
						if (!v[nx][ny]) {
							v[nx][ny] = true;
							pq.push({ nx, ny, nt });
						}
						break;
					}

					nx += dx[i];
					ny += dy[i];
				}
			}
		}
	}
	return -1;
}

int main() {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> lst[i][j];

	int sx, sy; cin >> sx >> sy;
	cout << bfs(sx, sy);
}