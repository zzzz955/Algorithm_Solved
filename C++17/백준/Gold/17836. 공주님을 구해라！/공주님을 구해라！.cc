#include<iostream>
#include<queue>
using namespace std;

int N, M, T;
int lst[100][100];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

struct Pos {
	int x, y, t;
	bool k;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};

void print(int x, int y, int t, int k) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (x == i && y == j) cout << 9 << " ";
			else cout << lst[i][j] << " ";
		}
		cout << "\n";
	}
	cout << t << " " << k << "\n";
}

int floodfill() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, 0, 0 });
	vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(2, 2e9)));
	dist[0][0][0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;
		bool ck = pos.k;
		//print(cx, cy, ct, ck);
		if (cx == N - 1 && cy == M - 1) return ct;
		if (ct > T) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
			bool nk = ck;
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (!nk) {
					if (lst[nx][ny] == 1) continue;
					else if (lst[nx][ny] == 2) nk = 1;
					if (dist[nx][ny][nk] > nt) {
						dist[nx][ny][nk] = nt;
						pq.push({ nx, ny, nt, nk });
					}
				}
				else {
					if (dist[nx][ny][nk] > nt) {
						dist[nx][ny][nk] = nt;
						pq.push({ nx, ny, nt, nk });
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> lst[i][j];

	int result = floodfill();
	if (result == -1) cout << "Fail";
	else cout << result;
}