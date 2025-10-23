#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 65;
int A[N][N];
int C[N][N];
int n, q;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool v[N][N];
struct Pos {
	int x, y;
};

void rotate(int l) {
	int r = 1;
	while (r <= n) {
		int c = 1;
		while (c <= n) {
			for (int i = 0; i < l; ++i) {
				for (int j = i + 1; j < l; ++j) {
					swap(A[r + i][c + j], A[r + j][c + i]);
				}
			}

			for (int i = 0; i < l; ++i) {
				reverse(A[r + i] + c, A[r + i] + c + l);
			}
			c += l;
		}
		r += l;
	}
}

void melt() {
	queue<Pos> q;
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			if (!A[x][y]) continue;

			int cnt = 0;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];

				if (0 < nx && nx <= n && 0 < ny && ny <= n && A[nx][ny]) cnt++;
			}

			if (cnt < 3) q.push({ x, y });
		}
	}

	while (!q.empty()) {
		auto pos = q.front(); q.pop();
		A[pos.x][pos.y]--;
	}
}

int floodfill(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = true;
	int cnt = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 < nx && nx <= n && 0 < ny && ny <= n && A[nx][ny] && !v[nx][ny]) {
				v[nx][ny] = true;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}
	return cnt;
}

int big() {
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (v[i][j]) continue;
			if (!A[i][j]) continue;
			mx = max(mx, floodfill(i, j));
		}
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	n = 1 << n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> A[i][j];
		}
	}

	while (q--) {
		int l; cin >> l;
		l = 1 << l;
		if (l > 1) rotate(l);
		melt();
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cnt += A[i][j];
		}
	}
	cout << cnt << "\n";
	cout << big();
}