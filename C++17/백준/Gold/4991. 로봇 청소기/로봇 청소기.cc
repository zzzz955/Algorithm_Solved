#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

int n, m;
string lst[20];
int bits[20][20];
bool v[20][20][1024];
struct Pos {
	int x, y, t, b;
};
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void print(int x, int y, int t, int b) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (x == i && y == j) cout << 'o';
			else cout << lst[i][j];
		}
		cout << "\n";
	}
	cout << t << " " << b << "\n";
}

int bfs(int d, int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy, 0, 0 });
	v[sx][sy][0] = 1;
	//cout << d << " " << pow(2, d) - 1 << "\n";

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t, cb = pos.b;
		if (cb == pow(2, d) - 1) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1, nb = cb;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != 'x') {
				if (lst[nx][ny] == '*') {
					//cout << nb << " " << bits[nx][ny] << " " << (nb & bits[nx][ny]) << '\n';
					if ((nb & bits[nx][ny]) == 0) nb += bits[nx][ny];
				}
				if (v[nx][ny][nb]) continue;
				//print(nx, ny, nt, nb);
				v[nx][ny][nb] = 1;
				q.push({ nx, ny, nt, nb });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> results;
	while (1) {
		cin >> m >> n;
		if (!m && !n) break;
		int d = 0, sx = 0, sy = 0;
		memset(v, 0, sizeof(v));
		memset(bits, 0, sizeof(bits));
		for (int i = 0; i < n; ++i) {
			cin >> lst[i];
			for (int j = 0; j < m; ++j) {
				if (lst[i][j] == '*') {
					bits[i][j] = pow(2, d);
					d++;
				}
				if (lst[i][j] == 'o') {
					sx = i, sy = j;
					lst[i][j] = '.';
				}
			}
		}
		results.push(bfs(d, sx, sy));
	}
	while (!results.empty()) {
		cout << results.front() << "\n";
		results.pop();
	}
}