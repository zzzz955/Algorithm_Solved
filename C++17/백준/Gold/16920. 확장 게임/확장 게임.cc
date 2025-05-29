#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1e3;
const int P = 10;
int n, m, p;
bool v[N][N];
int S[P];
int cnt[P];
struct Pos {
	int cx, cy, rm;
};
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<queue<Pos>> qs;

void floodfill(int pn) {
	queue<Pos> q;
	swap(q, qs[pn]);

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.cx, cy = pos.cy, rm = pos.rm;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nrm = rm - 1;

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
				v[nx][ny] = true;
				cnt[pn]++;

				if (nrm) q.push({ nx, ny, nrm });
				else qs[pn].push({nx, ny, S[pn]});
			}
		}
	}
}

bool get_con() {
	for (const auto& q : qs) {
		if (!q.empty()) return true;
	}
	return false;
}

void solution() {
	bool con = get_con();

	while (con) {
		for (int i = 1; i <= p; ++i) {
			if (qs[i].empty()) continue;
			floodfill(i);
		}
		con = get_con();
	}

	for (int i = 1; i <= p; ++i) cout << cnt[i] << " ";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> p;
	qs.resize(p + 1);
	for (int i = 1; i <= p; ++i) cin >> S[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if (ch == '.') continue;
			else if (ch == '#') v[i][j] = true;
			else {
				int num = ch - '0';
				v[i][j] = true;
				cnt[num]++;
				qs[num].push({i, j, S[num]});
			}
		}
	}

	solution();
}