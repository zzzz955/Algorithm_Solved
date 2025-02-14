#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int lst[1000][1000];
int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
struct Pos {
	int x, y;
};
queue<Pos> q1;

int solution() {
	int result = 0;
	while (!q1.empty()) {
		queue<Pos> q2;
		swap(q1, q2);
		while (!q2.empty()) {
			Pos pos = q2.front(); q2.pop();
			int cx = pos.x, cy = pos.y;

			for (int i = 0; i < 8; ++i) {
				int nx = cx + dx[i], ny = cy + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny]) {
					if (--lst[nx][ny] == 0) q1.push({ nx, ny });
				}
			}
		}
		if (!q1.empty()) result++;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if (ch == '.') {
				lst[i][j] = 0;
				q1.push({ i, j });
			}
			else lst[i][j] = ch - '0';
		}
	}
	cout << solution();
}