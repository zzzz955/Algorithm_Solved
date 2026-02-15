#include<iostream>
#include<queue>
using namespace std;

const int N = 100;
int n, m;
char arr[N][N];
bool v[N][N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int cx, cy;
};
queue<Pos> wolfs;

void bfs(Pos& wolf) {
	queue<Pos> q;
	q.push(wolf);
	v[wolf.cx][wolf.cy] = true;

	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			
			if (arr[nx][ny] == '.' && !v[nx][ny]) {
				v[nx][ny] = true;
				q.push({ nx, ny });
			}

			while (arr[nx][ny] == '+') {
				nx += dx[i];
				ny += dy[i];
			}

			if (arr[nx][ny] == '.') {
				if (v[nx][ny]) continue;
				v[nx][ny] = true;
				q.push({ nx, ny });
			}

			if (arr[nx][ny] == '#') {
				nx -= dx[i];
				ny -= dy[i];

				if (v[nx][ny]) continue;
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
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'W') wolfs.push({i, j});
		}
	}

	while (!wolfs.empty()) {
		Pos wolf = wolfs.front(); wolfs.pop();
		bfs(wolf);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == '.' && !v[i][j]) cout << 'P';
			else cout << arr[i][j];
		}
		cout << "\n";
	}
}