#include<iostream>
#include<queue>
using namespace std;

const int N = 50;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int n, m, ans;
int lst[N][N];
bool v[N][N];
struct Pos {
	int x, y;
};

void flood_fill(int sx, int sy, int ch) {
	queue<Pos> q;
	q.push({ sx, sy });
	queue<Pos> memo;
	memo.push({ sx, sy });
	v[sx][sy] = true;
	int mh = 9;
	bool flag = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 > nx || nx >= n || 0 > ny || ny >= m) {
				flag = false;
				continue;
			}

			if (lst[nx][ny] < ch) {
				flag = false;
				continue;
			}

			if (v[nx][ny]) continue;

			if (lst[nx][ny] == ch) {
				v[nx][ny] = true;
				q.push({ nx, ny });
				memo.push({ nx, ny });
			}
			else if (mh > lst[nx][ny]) mh = lst[nx][ny];
		}
	}

	if (flag) {
		while (!memo.empty()) {
			Pos pos = memo.front(); memo.pop();
			int x = pos.x, y = pos.y;

			lst[x][y] = mh;
			ans += mh - ch;
			v[x][y] = false;
		}
	}
}

void print() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << lst[i][j];
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int mx = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			lst[i][j] = c - '0';
			if (mx > lst[i][j]) mx = lst[i][j];
		}
	}

	for (int h = 1; h <= 9; ++h) {
		//cout << "\n";
		//print();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (v[i][j]) continue;
				if (lst[i][j] != h) continue;
				flood_fill(i, j, h);
			}
		}
	}
	cout << ans;
}