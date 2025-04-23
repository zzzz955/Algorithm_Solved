#include<iostream>
#include<queue>
using namespace std;

const int N = 2222;
int n;
int lst[N][N];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
struct Pos {
	int cx, cy, cv, ch;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, 0, lst[0][0] });
	vector<vector<int>> dist(n, vector<int>(n, 2e9));
	dist[0][0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.cx, cy = pos.cy, cv = pos.cv, ch = pos.ch;
		if (dist[cx][cy] < cv) continue;
		if (cx == n - 1 && cy == n - 1) return cv;
		//cout << "x:" << cx << " y:" << cy << " v:" << cv << " h:" << ch << "\n";

		for (int i = 0; i < 2; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nv = cv;

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (ch <= lst[nx][ny]) {
					nv += lst[nx][ny] - ch + 1;
				}

				if (dist[nx][ny] > nv) {
					dist[nx][ny] = nv;
					pq.push({ nx, ny, nv, lst[nx][ny] });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> lst[i][j];
		}
	}

	cout << dijkstra();
}