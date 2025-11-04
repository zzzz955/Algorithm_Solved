#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int r, c;
char map[101][101];
struct Pos {
	int x, y;
};
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

vector<vector<int>> bfs(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy });
	vector<vector<int>> dist(r + 1, vector<int>(c + 1, -1));
	dist[sx][sy] = 0;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, ct = dist[cx][cy];

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (1 <= nx && nx <= r && 1 <= ny && ny <= c && !map[nx][ny] && dist[nx][ny] == -1) {
				dist[nx][ny] = ct + 1;
				q.push({ nx, ny });
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> map[i][j];
			map[i][j] -= '0';
		}
	}

	vector<vector<int>> dist[3];
	for (int i = 0; i < 3; ++i) {
		int x, y; cin >> x >> y;
		auto res = bfs(x, y);
		dist[i] = res;
	}

	int mn = 2e9, cnt = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			bool flag = true;
			int mx = 0;
			for (int k = 0; k < 3; ++k) {
				if (dist[k][i][j] == -1) {
					flag = false;
					break;
				}
				mx = max(mx, dist[k][i][j]);
			}

			if (!flag) continue;

			if (mn > mx) {
				mn = mx;
				cnt = 1;
			}
			else if (mn == mx) ++cnt;
		}
	}

	if (mn == 2e9) cout << -1;
	else cout << mn << "\n" << cnt;
}