#include<iostream>
#include<queue>
using namespace std;

const int N = 1000;
int n, m;
bool v[N][N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int cx, cy;
};

void bfs(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy });

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.cx, cy = pos.cy;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0) nx = n - 1;
			if (nx == n) nx = 0;
			if (ny < 0) ny = m - 1;
			if (ny == m) ny = 0;

			if (v[nx][ny]) continue;
			v[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j]) continue;
			v[i][j] = true;
			ans++;
			bfs(i, j);
		}
	}
	cout << ans;
}