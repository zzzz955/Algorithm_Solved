#include<iostream>
#include<queue>
using namespace std;

int n, ans = 2e9;
int lst[1000][1000];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

struct Pos {
	int x, y, d;
	bool operator<(const Pos& other) const {
		return d > other.d;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, 0 });
	vector<vector<int>> h(n, vector<int>(n, 2e9));
	h[0][0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cd = pos.d;
		if (cx == n - 1 && cy == n - 1) return cd;
		//cout << cx << " " << cy << " " << cd << "\n";

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				int nd = max(cd, abs(lst[nx][ny] - lst[cx][cy]));
				if (h[nx][ny] > nd) {
					h[nx][ny] = nd;
					pq.push({ nx, ny, nd });
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