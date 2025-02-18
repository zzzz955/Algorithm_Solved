#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int n, m, ans;
int lst[20][20];
bool v[20][20];
struct Pos {
	int x, y, g;
};
int dx[] = { 1, -1, 0 ,0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = true;
	int cnt = 1;
	bool result = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cg = pos.g;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != 1 && !v[nx][ny]) {
				if (lst[nx][ny] == 0) {
					if (!result) continue;
					else {
						result = false;
						continue;
					}
				}
				v[nx][ny] = true;
				cnt++;
				q.push({ nx, ny });
			}
		}
	}
	return result ? cnt : 0;
}

int solve() {
	memset(v, 0, sizeof(v));
	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (lst[i][j] == 2 && !v[i][j]) {
				result += bfs(i, j);
			}
		}
	}
	return result;
}

void bt(int level, int x, int y) {
	if (level == 2) {
		ans = max(ans, solve());
		return;
	}

	for (int i = x; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == x && j <= y) continue;
			if (!lst[i][j]) {
				lst[i][j] = 1;
				bt(level + 1, i, j);
				lst[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> lst[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!lst[i][j]) {
				lst[i][j] = 1;
				bt(1, i, j);
				lst[i][j] = 0;
			}
		}
	}
	cout << ans;
}