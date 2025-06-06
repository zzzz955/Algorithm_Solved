#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int N = 102;
int t, n, m;
int lst[N][N];
bool v[N][N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y, c;
	bool operator<(const Pos& other) const {
		return c > other.c;
	}
};

vector<vector<int>> dijkstra(int sx, int sy) {
	priority_queue<Pos> pq;
	pq.push({ sx, sy, 0 });
	vector<vector<int>> dist(n + 2, vector<int>(m + 2, 2e9));
	dist[sx][sy] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cc = pos.c;
		//cout << cx << " " << cy << " " << cc << "\n";

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nc = cc;

			if (0 <= nx && nx < n + 2 && 0 <= ny && ny < m + 2 && lst[nx][ny] != 1) {
				if (lst[nx][ny] == -1) nc++;
				if (dist[nx][ny] > nc) {
					dist[nx][ny] = nc;
					pq.push({ nx, ny, nc });
				}
			}
		}
	}
	//cout << "\n";
	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;

		memset(lst, 0, sizeof(lst));
		int x1, y1, x2, y2;
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				char ch; cin >> ch;
				if (ch == '.') continue;
				else if (ch == '*') lst[i][j] = 1;
				else if (ch == '#') lst[i][j] = -1;
				else if (ch == '$') {
					if (flag) {
						x1 = i, y1 = j;
						flag = false;
					}
					else x2 = i, y2 = j;
				}
			}
		}

		memset(v, false, sizeof(v));
		vector<vector<int>> dist1 = dijkstra(0, 0);

		memset(v, false, sizeof(v));
		vector<vector<int>> dist2 = dijkstra(x1, y1);

		memset(v, false, sizeof(v));
		vector<vector<int>> dist3 = dijkstra(x2, y2);

		int ans = 2e9;
		for (int i = 0; i <= n + 1; ++i) {
			for (int j = 0; j <= m + 1; ++j) {
				if (lst[i][j] == 1) continue;
				int sum = dist1[i][j] + dist2[i][j] + dist3[i][j];
				if (lst[i][j] == -1) sum -= 2;
				if (ans > sum) ans = sum;
			}
		}
		cout << ans << "\n";
	}
}