#include<iostream>
#include<queue>
using namespace std;

const int N = 50;
int n, m, idx, sx, sy, ex, ey;
int lst[N][N];
bool v[1 << 5][N][N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int cx, cy, ct, cc;
};

int bfs() {
	queue<Pos> q;
	q.push({ sx, sy, 0, 0 });
	v[0][sx][sy] = true;
	int tar = (1 << idx) - 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.cx, cy = pos.cy, ct = pos.ct, cc = pos.cc;
		//cout << cx << " " << cy << " " << ct << " " << cc << "\n";
		if (cx == ex && cy == ey && cc == tar) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1, nc = cc;

			if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != -1) {
				if (lst[nx][ny]) nc |= 1 << lst[nx][ny] - 1;

				if (v[nc][nx][ny]) continue;
				v[nc][nx][ny] = true;
				q.push({ nx, ny, nt, nc });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			if (c == '#') lst[i][j] = -1;
			else if (c == 'X') lst[i][j] = ++idx;
			else if (c == 'S') sx = i, sy = j;
			else if (c == 'E') ex = i, ey = j;
			//cout << lst[i][j] << " ";
		}
		//cout << "\n";
	}

	cout << bfs();
}