#include<iostream>
#include<queue>
using namespace std;

const int N = 100;
int n, m;
char arr[N][N];
int ax, ay;
struct Pos {
	int x, y;
};
int dx[] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dy[] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int get_dist(int tx, int ty) {
	return abs(tx - ax) + abs(ty - ay);
}

void print(int time) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << (i == ax && j == ay ? 'I' : arr[i][j]);
		}
		cout << "\n";
	}
	cout << "time: " << time << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	queue<Pos> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			arr[i][j] = '.';

			if (c == 'R') {
				arr[i][j] = 'R';
				q.push({ i, j });
			}
			else if (c == 'I') {
				ax = i, ay = j;
			}
		}
	}

	string op; cin >> op;
	for (int i = 0; i < op.size(); ++i) {
		int idx = op[i] - '0';

		ax += dx[idx];
		ay += dy[idx];
		if (arr[ax][ay] == 'R') {
			cout << "kraj " << i + 1;
			return 0;
		}

		queue<Pos> temp;
		while (!q.empty()) {
			auto [cx, cy] = q.front(); q.pop();
			arr[cx][cy] = '.';

			int dist = 9999;
			int nx = -1, ny = -1;
			for (int i = 1; i <= 9; ++i) {
				if (i == 5) continue;

				int tx = cx + dx[i], ty = cy + dy[i];
				int n_dist = get_dist(tx, ty);
				if (n_dist < dist) {
					dist = n_dist;
					nx = tx, ny = ty;
				}
			}
			temp.push({ nx, ny });
		}

		while (!temp.empty()) {
			auto [x, y] = temp.front(); temp.pop();
			if (x == ax && y == ay) {
				cout << "kraj " << i + 1;
				return 0;
			}
			else if (arr[x][y] == '.') arr[x][y] = 'R';
			else arr[x][y] = 'B';
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] == 'R') q.push({ i, j });
				else if (arr[i][j] == 'B') arr[i][j] = '.';
			}
		}

		//print(i + 1);
	}

	arr[ax][ay] = 'I';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}