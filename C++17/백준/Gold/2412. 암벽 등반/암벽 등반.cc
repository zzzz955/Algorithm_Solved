#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

const int Y = 2e5;
int n, t;
unordered_map<int, unordered_map<int, bool>> v;
int d[] = { -2, -1, 0, 1, 2 };
struct Pos {
	int x, y, c;
};

int bfs() {
	queue<Pos> q;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cc = pos.c;
		//cout << cx << " " << cy << " " << cc << "\n";
		if (cy == t) return cc;

		for (int i = 0; i < 5; ++i) {
			int nx = cx + d[i];
			if (0 <= nx && nx <= Y) {
				for (int j = 0; j < 5; ++j) {
					int ny = cy + d[j];
					if (0 <= ny && ny <= Y && v[nx][ny]) {
						v[nx].erase(ny);
						q.push({nx, ny, cc + 1});
					}
				}
			}
			
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;
	while (n--) {
		int x, y; cin >> x >> y;
		v[x][y] = true;
	}

	cout << bfs();
}