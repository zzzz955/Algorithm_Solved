#include<iostream>
#include<queue>
using namespace std;

int n, m, sx, sy;
string lst[1000], orders;
char ans[1000][1000];
bool v[1000][1000];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y;
};

void floodfill() {
	queue<Pos> q;
	q.push({ sx, sy });
	ans[sx][sy] = '.';
	v[sx][sy] = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] == lst[sx][sy] && !v[nx][ny]) {
				v[nx][ny] = true;
				ans[nx][ny] = '.';
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
		cin >> lst[i];
		for (int j = 0; j < m; ++j) {
			ans[i][j] = '#';
		}
	}

	cin >> sx >> sy >> orders;
	--sx, --sy;
	int idx = -1;
	while (++idx < orders.size()) {
		const char& op = orders[idx];
		if (op == 'U') sx -= 1;
		else if (op == 'D') sx += 1;
		else if (op == 'L') sy -= 1;
		else if (op == 'R') sy += 1;
		else floodfill();
	}
	ans[sx][sy] = '.';
	for (int i = 0; i < 4; ++i) {
		int nx = sx + dx[i], ny = sy + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) ans[nx][ny] = '.';
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
}