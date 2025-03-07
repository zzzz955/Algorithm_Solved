#include<iostream>
#include<queue>
using namespace std;

int n, m, sx, sy, ex, ey;
int lst[50][50];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y, g, ng;
	bool operator<(const Pos& other) const {
		if (g == other.g) return ng > other.ng;
		return g > other.g;
	}
};

void print(int x, int y, int g, int ng) {
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (x == i && y == j) cout << '#';
			else if (ex == i && ey == j) cout << "@";
			else cout << lst[i][j];
		}
		cout << "\n";
	}
	cout << "쓰레기를 지난 횟수 : " << g << " 쓰레기 옆을 지난 횟수 : " << ng << "\n";
}

pair<int, int> dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ sx, sy, 0, 0 });
	vector<vector<pair<int, int>>> dist(n, vector<pair<int, int>>(m, {2e9, 2e9}));
	dist[sx][sy] = { 0, 0 };

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cg = pos.g, cng = pos.ng;
		//print(cx, cy, cg, cng);
		if (cx == ex && cy == ey) return { cg, cng };

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], ng = cg, nng = cng;
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (lst[nx][ny]) ng++;
				else if (nx != ex || ny != ey){
					for (int j = 0; j < 4; ++j) {
						int nnx = nx + dx[j], nny = ny + dy[j];
						if (0 <= nnx && nnx < n && 0 <= nny && nny < m && lst[nnx][nny]) {
							nng++;
							break;
						}
					}
				}
				
				if (dist[nx][ny].first > ng) {
					dist[nx][ny].first = ng;
					dist[nx][ny].second = nng;
					pq.push({ nx, ny, ng, nng });
				}
				else if (dist[nx][ny].first == ng && dist[nx][ny].second > nng) {
					dist[nx][ny].second = nng;
					pq.push({ nx, ny, ng, nng });
				}
			}
		}
	}
	return { -1, -1 };
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'g') lst[i][j] = 1;
			else if (s[j] == 'F') sx = i, sy = j;
			else if (s[j] == 'S') ex = i, ey = j;
		}
	}
	pair<int, int> result = dijkstra();
	cout << result.first << " " << result.second;
}