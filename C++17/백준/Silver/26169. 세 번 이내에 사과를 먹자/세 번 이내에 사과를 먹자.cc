#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int sx, sy;
int lst[5][5];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y, c, t, b;
};

int bfs() {
	queue<Pos> q;
	q.push({ sx, sy, 0, 0, (int)pow(2, sx * 5 + sy) });

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cc = pos.c, ct = pos.t, cb = pos.b;
		if (cc == 2) return 1;
		if (ct == 3) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nc = cc, nt = ct + 1;
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && lst[nx][ny] != -1 && !(cb & (int)pow(2, nx * 5 + ny))) {
				if (lst[nx][ny]) nc++;
				q.push({ nx, ny, nc, nt, cb + (int)pow(2, nx * 5 + ny)});
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> lst[i][j];

	cin >> sx >> sy;
	cout << bfs();
}