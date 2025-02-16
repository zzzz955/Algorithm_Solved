#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n, m, sx, sy, idx = 1, ans = 2e9;
string init[1000];
int lst[1000][1000];
bool v[1000][1000];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y, t;
};
struct Edge {
	int idx, t;
};
vector<Edge> edges[22];
Pos starts[22];
bool pv[22];
vector<int> path;

void bfs(int index, Pos start) {
	queue<Pos> q;
	q.push({ start.x, start.y, 0 });
	v[start.x][start.y] = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != -1 && !v[nx][ny]) {
				v[nx][ny] = true;
				if (lst[nx][ny]) edges[index].push_back({ lst[nx][ny], nt });
				q.push({ nx, ny, nt });
			}
		}
	}
}

void bt(int level, int node, int sum) {
	if (ans <= sum) return;
	if (level == 5) {
		ans = min(ans, sum);
		return;
	}

	for (const Edge& e : edges[node]) {
		if (pv[e.idx]) continue;
		pv[e.idx] = true;
		path.push_back(e.idx);
		bt(level + 1, e.idx, sum + e.t);
		pv[e.idx] = false;
		path.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> init[i];
		for (int j = 0; j < m; ++j) {
			if (init[i][j] == '.') lst[i][j] = 0;
			else if (init[i][j] == 'X') lst[i][j] = -1;
			else if (init[i][j] == 'K') {
				lst[i][j] = ++idx;
				starts[idx] = { i, j };
			}
			else {
				sx = i, sy = j;
				lst[i][j] = 1;
				starts[1] = { i, j };
			}
		}
	}

	if (idx < 6) {
		cout << -1;
		return 0;
	}

	for (int i = 1; i <= idx; ++i) {
		memset(v, 0, sizeof(v));
		bfs(i, starts[i]);
	}
	
	pv[1] = true;
	bt(0, 1, 0);

	if (ans == 2e9) cout << -1;
	else cout << ans;
}