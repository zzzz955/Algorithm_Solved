#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1000;
int n, m;
int l, r;
struct Pos {
	int cx, cy, ll, lr;
};
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int d[N][N];

int bfs(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy, l, r });
	d[sx][sy] = l;
	int cnt = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.cx, cy = pos.cy, cll = pos.ll, clr = pos.lr;

		for (int i = 0; i < 4; ++i) {
			if (i == 2 && !clr) continue;
			if (i == 3 && !cll) continue;
			int nx = cx + dx[i], ny = cy + dy[i], nlr = i == 2 ? clr - 1 : clr, nll = i == 3 ? cll - 1 : cll;

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (d[nx][ny] >= nll) continue;
				if (d[nx][ny] == -1) ++cnt;
				d[nx][ny] = nll;
				q.push({ nx, ny, nll, nlr });
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> l >> r;
	int sx, sy;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			if (c == '1') d[i][j] = 1001;
			else if (c == '2') sx = i, sy = j;
		}
	}

	cout << bfs(sx, sy);
}