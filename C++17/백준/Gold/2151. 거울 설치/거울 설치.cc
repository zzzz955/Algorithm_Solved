#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n, l, sx, sy, ex, ey, ans = 2e9;
string lst[50];
bool v[2500][50][50];
struct Pos {
	int x, y, d, c;
	bool operator<(const Pos& other) const {
		return c > other.c;
	}
};
vector<Pos> mirrors;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void print(int x, int y) {
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == x && j == y) cout << "@";
			else cout << lst[i][j];
		}
		cout << "\n";
	}
}

int dijkstra() {
	priority_queue<Pos> pq;
	for (int i = 0; i < 4; ++i) pq.push({ sx, sy, i, 0 });
	v[0][sx][sy] = true;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cd = pos.d, cc = pos.c;
		if (cx == ex && cy == ey) return cc;

		int nx = cx + dx[cd], ny = cy + dy[cd];
		while (0 <= nx && nx < n && 0 <= ny && ny < n && lst[nx][ny] != '*' && !v[cc][nx][ny]) {
			if (lst[nx][ny] == '!') {
				v[cc + 1][nx][ny] = true;
				pq.push({ nx, ny, (cd + 1) % 4, cc + 1 });
				pq.push({ nx, ny, (cd + 3) % 4, cc + 1 });
			}
			else if (lst[nx][ny] == '#') {
				v[cc][nx][ny] = true;
				pq.push({ nx, ny, -1, cc });
				continue;
			}
			nx += dx[cd];
			ny += dy[cd];
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		for (int j = 0; j < n; ++j) {
			if (lst[i][j] == '#') {
				if (!idx) {
					sx = i, sy = j;
					idx++;
				}
				else ex = i, ey = j;
			}
		}
	}
	l = mirrors.size();
	cout << dijkstra();
}