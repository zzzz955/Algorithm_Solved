#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 500;
int n, m;
bool arr[N][N];
int dxf[] = { -1, 1, -1, 0, 0, 1 };
int dyf[] = { -1, 1, 0, -1, 1, 0 };
int dxt[] = { -1, 1, -1, 0, 0, 1 };
int dyt[] = { 1, -1, 0, -1, 1, 0 };
struct Pos {
	int cx, cy, ct;
	bool cf;
	bool operator<(const Pos& other) const {
		return ct > other.ct;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, arr[0][0], false});
	vector<vector<vector<int>>> dist(2, vector<vector<int>>(n, vector<int>(m, 2e9)));
	dist[0][0][0] = arr[0][0];

	while (!pq.empty()) {
		auto [cx, cy, ct, cf] = pq.top(); pq.pop();

		if (dist[cf][cx][cy] < ct) continue;
		//cout << cx << " " << cy << " " << ct << " " << cf << "\n";
		if (cx == n - 1 && cy == m - 1 && !cf) return ct;
		
		if (!cf) {
			for (int i = 0; i < 6; ++i) {
				int nx = cx + dxf[i], ny = cy + dyf[i];

				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					int nt = ct;
					if (i < 2 && arr[nx][ny] != cf) ++nt;
					if (i >= 2 && arr[nx][ny] == cf) ++nt;
					bool nf = (ct == nt ? arr[nx][ny] : !arr[nx][ny]);

					if (dist[nf][nx][ny] > nt) {
						dist[nf][nx][ny] = nt;
						pq.push({ nx, ny, nt, nf });
					}
				}
			}
		}
		else {
			for (int i = 0; i < 6; ++i) {
				int nx = cx + dxt[i], ny = cy + dyt[i];

				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					int nt = ct;
					if (i < 2 && arr[nx][ny] != cf) ++nt;
					if (i >= 2 && arr[nx][ny] == cf) ++nt;
					bool nd = (ct == nt ? arr[nx][ny] : !arr[nx][ny]);

					if (dist[nd][nx][ny] > nt) {
						dist[nd][nx][ny] = nt;
						pq.push({ nx, ny, nt, nd });
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

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			arr[i][j] = (c == '/' ? true : false);
		}
	}

	int res = dijkstra();
	if (res == -1) cout << "NO SOLUTION";
	else cout << res;
}