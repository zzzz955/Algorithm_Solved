#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int sx, sy, sd, ex, ey, ed;
int lst[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
struct Pos {
	int x, y, t, d;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};

void print(int x, int y, int t, int d) {
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (x == i && y == j) {
				if (d == 0) cout << "→ ";
				if (d == 1) cout << "← ";
				if (d == 2) cout << "↓ ";
				if (d == 3) cout << "↑ ";
			}
			else cout << lst[i][j] << " ";
		}
		cout << "\n";
	}
	cout << t << " " << d << "\n";
}

int bfs() {
	priority_queue<Pos> pq;
	pq.push({ --sx, --sy, 0, --sd });
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, 2e9)));
	dist[sx][sy][sd] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t, cd = pos.d;
		//print(cx, cy, ct, cd);

		int nd1 = cd == 2 || cd == 3 ? 0 : 2;
		int nd2 = cd == 2 || cd == 3 ? 1 : 3;
		
		if (dist[cx][cy][nd1] > ct + 1) {
			dist[cx][cy][nd1] = ct + 1;
			pq.push({ cx, cy, ct + 1, nd1 });
		}

		for (int i = 1; i <= 3; ++i) {
			int nx = cx + dx[cd] * i, ny = cy + dy[cd] * i;
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (lst[nx][ny]) break;
				if (dist[nx][ny][cd] > ct + 1) {
					dist[nx][ny][cd] = ct + 1;
					pq.push({ nx, ny, ct + 1, cd });
				}
			}
		}

		if (dist[cx][cy][nd2] > ct + 1) {
			dist[cx][cy][nd2] = ct + 1;
			pq.push({ cx, cy, ct + 1, nd2 });
		}
	}
	return dist[--ex][--ey][--ed];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> lst[i][j];

	cin >> sx >> sy >> sd >> ex >> ey >> ed;
	cout << bfs();
}