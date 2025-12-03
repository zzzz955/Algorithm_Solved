#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1000;
int M[N][N];
bool v[N][N];
int n, m, k;
struct Pos {
	int x, y;
};
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int init(queue<Pos>& q, int d) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		v[i][0] = true;
		if (M[i][0] <= d) {
			++cnt;
			q.push({ i, 0 });
		}

		if (m == 1) continue;
		v[i][m - 1] = true;
		if (M[i][m - 1] <= d) {
			++cnt;
			q.push({ i, m - 1 });
		}
	}

	for (int j = 1; j < m - 1; ++j) {
		v[0][j] = true;
		if (M[0][j] <= d) {
			++cnt;
			q.push({ 0, j });
		}
	}
	return cnt;
}

bool bfs(int d) {
	memset(v, 0, sizeof(v));
	queue<Pos> q;
	int cnt = init(q, d);

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		if (cnt >= k) return true;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
				v[nx][ny] = true;
				if (M[nx][ny] <= d) {
					++cnt;
					q.push({ nx, ny });
				}
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> M[i][j];
			if (mx < M[i][j]) mx = M[i][j];
		}
	}

	int l = 1, r = mx, d = mx;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (bfs(mid)) {
			d = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << d;
}