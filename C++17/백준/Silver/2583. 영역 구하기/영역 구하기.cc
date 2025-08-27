#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, k;
bool v[100][100];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<int> a;
struct Pos {
	int x, y;
};

void floodfill(int sx, int sy) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = true;
	int cnt = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
				v[nx][ny] = true;
				cnt++;
				q.push({ nx, ny });
			}
		}
	}
	a.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j) {
				v[i][j] = true;
			}
		}
	}

	//cout << "\n";
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		cout << v[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!v[i][j]) floodfill(i, j);
		}
	}

	cout << a.size() << "\n";
	sort(a.begin(), a.end());
	for (int i : a) cout << i << " ";
}