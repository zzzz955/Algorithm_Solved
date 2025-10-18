#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

const int N = 51;
int r, c, p, n, t;
char map[N][N];
int lst[N][N];
struct Pos {
	int x, y;
};
unordered_map<int, Pos> poses;
unordered_map<int, string> names;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool dfs(int cn, vector<int>& match, vector<int>& v, const vector<unordered_set<int>>& edges) {
	for (int nn : edges[cn]) {
		if (!match[nn]) {
			match[nn] = cn;
			return true;
		}
	}

	for (int nn : edges[cn]) {
		if (v[nn] == t) continue;
		v[nn] = t;

		if (dfs(match[nn], match, v, edges)) {
			match[nn] = cn;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;
	string name = "";
	for (int i = 1; i <= r; ++i) {
		name.clear();

		for (int j = 1; j <= c; ++j) {
			char a; cin >> a;

			if (a == '.' || a == 'x') {
				if (!name.empty()) {
					names[++n] = name;
					name.clear();
				}
				if (a == 'x') poses[++p] = { i, j };
			}
			else {
				name += a;
				lst[i][j] = n + 1;
			}
		}
		if (!name.empty()) {
			names[++n] = name;
			name.clear();
		}
	}

	vector<unordered_set<int>> edges(p + 1);
	for (const auto& x : poses) {
		Pos pos = x.second;
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 8; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 < nx && nx <= r && 0 < ny && ny <= c) {
				if (lst[nx][ny]) edges[x.first].insert(lst[nx][ny]);
			}
		}
	}

	vector<int> match(n + 1, 0);
	vector<int> v(n + 1, 0);
	for (const auto& x : poses) {
		t++;
		dfs(x.first, match, v, edges);
	}

	for (int i = 1; i <= n; ++i) {
		if (!match[i]) continue;

		int x = match[i];
		Pos pos = poses[x];
		cout << pos.x << " " << pos.y << " " << names[i] << "\n";
	}
}