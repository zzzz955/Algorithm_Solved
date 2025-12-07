#include<iostream>
using namespace std;

const int N = 100;
int a[N][N];
int n, m, t, ans;
int dx[] = { 1, -1, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0 };

void bt(int cx, int cy, int ct, int ce) {
	if (ct == t) {
		ans = max(ans, ce);
		return;
	}

	for (int i = 0; i < 5; ++i) {
		int nx = cx + dx[i], ny = cy + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != -1) {
			if (a[nx][ny]) {
				a[nx][ny] = 0;
				bt(nx, ny, ct + 1, ce + 1);
				a[nx][ny] = 1;
			}
			else bt(nx, ny, ct + 1, ce);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	int sx = -1, sy = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			if (c == '#') a[i][j] = -1;
			else if (c == 'S') a[i][j] = 1;
			else if (c == 'G') sx = i, sy = j;
		}
	}

	bt(sx, sy, 0, 0);
	cout << ans;
}