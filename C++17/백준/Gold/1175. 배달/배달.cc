#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int n, m, sx, sy;
string lst[50];
bool v[50][50][4][5];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y, t, d, c;
};
unordered_map<int, int> dic;

int bfs() {
	queue<Pos> q;
	q.push({ sx, sy, 0, -1, 0 });
	v[sx][sy][0][4] = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t, cd = pos.d, cc = pos.c;
		if (cc == 3) return ct;

		for (int i = 0; i < 4; ++i) {
			if (i == cd) continue;
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1, nc = cc;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != '#') {
				if (lst[nx][ny] == 'C' && !(cc & dic[nx * m + ny])) nc += dic[nx * m + ny];
				if (v[nx][ny][nc][i]) continue;
				v[nx][ny][nc][i] = true;
				q.push({ nx, ny, nt, i, nc });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int idx = 1;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		for (int j = 0; j < m; ++j) {
			if (lst[i][j] == 'S') {
				sx = i, sy = j;
				lst[i][j] = '.';
			}
			else if (lst[i][j] == 'C') dic[i * m + j] = idx++;
		}
	}
	cout << bfs();
}