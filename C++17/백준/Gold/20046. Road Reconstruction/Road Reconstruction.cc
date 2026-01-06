#include<iostream>
#include<queue>
using namespace std;

const int N = 1e3;
int arr[N][N];
int n, m;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int cx, cy, cv;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, arr[0][0] });
	vector<vector<int>> dist(n, vector<int>(m, 2e9));
	dist[0][0] = arr[0][0];

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.cx, cy = pos.cy, cv = pos.cv;

		if (dist[cx][cy] < cv) continue;
		if (cx == n - 1 && cy == m - 1) return cv;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] != -1) {
				int nv = cv + arr[nx][ny];
				
				if (dist[nx][ny] > nv) {
					dist[nx][ny] = nv;
					pq.push({ nx, ny, nv });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	cout << (arr[0][0] == -1 ? -1 : dijkstra());
}