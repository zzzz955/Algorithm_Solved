#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 300;
int n, m, sx, sy;
int lst[N][N];
bool v[N][N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y;
};
queue<Pos> q1;

bool bfs() {
	queue<Pos> q2;
	swap(q1, q2);
	while (!q2.empty()) {
		Pos pos = q2.front(); q2.pop();
		int cx = pos.x, cy = pos.y;
		
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
				v[nx][ny] = true;
				if (!lst[nx][ny]) {
					q2.push({ nx, ny });
				}
				else if (lst[nx][ny] == 1) {
					lst[nx][ny] = 0;
					q1.push({ nx, ny });
				}
				else if (lst[nx][ny] == 2) return true;
			}
		}
	}
	return false;
}

int solve() {
	q1.push({ --sx, --sy });
	v[sx][sy] = true;
	int ans = 0;
	while (++ans) if (bfs()) return ans;
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int x2, y2; cin >> sx >> sy >> x2 >> y2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if (ch == '1') lst[i][j] = 1;
			else if (ch == '#') lst[i][j] = 2;
		}
	}

	cout << solve();
}