#include<iostream>
#include<queue>
using namespace std;

const int N = 500;
const int K = 1 << 10;
int n, h, d;
int lst[N][N];
bool v[K][N][N];
int sx, sy, ex, ey;
struct Pos {
	int cx, cy, ch, cd, ct, ck;
};
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs() {
	queue<Pos> q;
	q.push({ sx, sy, h, 0, 0, 0 });
	v[0][sx][sy] = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.cx, cy = pos.cy, ch = pos.ch, cd = pos.cd, ct = pos.ct, ck = pos.ck;
		if (cx == ex && cy == ey) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nh = cd ? ch : ch - 1, nd = cd ? cd - 1 : cd, nt = ct + 1, nk = ck;
			if (nh == -1) continue;
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (lst[nx][ny] && !(lst[nx][ny] & ck)) {
					nk |= lst[nx][ny];
					nd = d;
				}
				if (v[ck][nx][ny]) continue;
				v[nk][nx][ny] = true;
				q.push({ nx, ny, nh, nd, nt, nk });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h >> d;
	int u = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c; cin >> c;
			if (c == 'U') lst[i][j] = (1 << (u++));
			else if (c == 'S') sx = i, sy = j;
			else if (c == 'E') ex = i, ey = j;
			//cout << lst[i][j] << " ";
		}
		//cout << "\n";
	}

	cout << bfs();
}