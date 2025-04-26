#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int lst1[30][30], lst2[30][30];
bool v[30][30];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y;
};

void bfs(int sx, int sy, int c, int g) {
	queue<Pos> q;
	q.push({ sx, sy });
	lst1[sx][sy] = g;
	v[sx][sy] = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && lst1[nx][ny] == c) {
				v[nx][ny] = true;
				lst1[nx][ny] = g;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!k) cin >> lst1[i][j];
				else cin >> lst2[i][j];
			}
		}
	}

	bool flag = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (lst1[i][j] != lst2[i][j]) {
				bfs(i, j, lst1[i][j], lst2[i][j]);
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	//cout << "\n";
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		cout << lst1[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	//cout << "\n";
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		cout << lst2[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (lst1[i][j] != lst2[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}