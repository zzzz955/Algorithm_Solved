#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1000;
int n, m, k;
bool lst[N][N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y;
};

int bfs() {
	int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;
	queue<Pos> q;
	q.push({ sx, sy });
	vector<vector<int>> dist(n, vector<int>(m, 2e9));
	dist[sx][sy] = 0;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;
		//cout << cx << " " << cy << "\n";
		if (cx == ex && cy == ey) return dist[ex][ey];

		for (int i = 0; i < 4; ++i) {
			for (int j = 1; j <= k; ++j) {
				int nx = cx + dx[i] * j, ny = cy + dy[i] * j;
				if (nx < 0 || n <= nx || ny < 0 || m <= ny) break;
				if (lst[nx][ny]) break;
				if (dist[nx][ny] < dist[cx][cy] + 1) break;
				if (dist[nx][ny] == dist[cx][cy] + 1) continue;
				dist[nx][ny] = dist[cx][cy] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("BOJ16930.txt", "r", stdin);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			if (c == '#') lst[i][j] = true;
		}
	}
	cout << bfs();
}