#include<iostream>
#include<queue>
using namespace std;

const int N = 1001;
bool lst[N][N];
bool v[N][N];
int pre[N][N];
int n, m, q;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y;
};

void floodfill(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 < nx && nx <= n && 0 < ny && ny <= m && !lst[nx][ny] && !v[nx][ny]) {
				v[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char a; cin >> a;
			lst[i][j] = a - '0';
		}
	}

	floodfill(1, 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!v[i][j]) lst[i][j] = true;
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + lst[i][j];
			//cout << pre[i][j] << " ";
		}
		//cout << "\n";
	}

	cin >> q;
	while (q--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int sum = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
		if (sum) cout << "No " << sum << "\n";
		else cout << "Yes\n";
	}
}