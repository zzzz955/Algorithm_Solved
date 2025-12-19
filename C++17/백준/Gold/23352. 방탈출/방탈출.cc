#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 50;
int a[N][N];
bool v[N][N];
int n, m;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int cx, cy, cl;
};

pair<int, int> flood_fill(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy, 0 });
	v[sx][sy] = true;
	int len = 0;
	int f = a[sx][sy];
	int l = a[sx][sy];

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.cx, cy = pos.cy, cl = pos.cl;
		if (cl > len) {
			len = cl;
			l = a[cx][cy];
		}
		else if (cl == len) l = max(l, a[cx][cy]);

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && a[nx][ny]) {
				v[nx][ny] = true;
				q.push({ nx, ny, cl + 1 });
			}
		}
	}
	return { len, f + l };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	int mx = 0, ml = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!a[i][j]) continue;
			memset(v, false, sizeof(v));
			auto res = flood_fill(i, j);
			if (res.first > ml) {
				ml = res.first;
				mx = res.second;
			}
			else if (res.first == ml) mx = max(mx, res.second);
		}
	}
	cout << mx;
}