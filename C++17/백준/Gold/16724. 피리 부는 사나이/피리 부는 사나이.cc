#include<iostream>
#include<unordered_set>
using namespace std;

const int N = 1000;
int n, m;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int lst[N][N];
int g[N * N];
unordered_set<int> dic;

int Find(int a) {
	if (g[a] == a) return a;
	return g[a] = Find(g[a]);
}

void dfs(int cx, int cy) {
	int d = lst[cx][cy];
	int nx = cx + dx[d], ny = cy + dy[d];
	int cg = Find(cx * m + cy);
	int ng = Find(nx * m + ny);
	//cout << cx << " " << cy << " " << nx << " " << ny << "\n";

	if (cg < ng) {
		g[ng] = cg;
		dfs(nx, ny);
	}
	else if (cg >= ng) {
		g[cg] = ng;
		return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			if (c == 'R') lst[i][j] = 1;
			else if (c == 'U') lst[i][j] = 2;
			else if (c == 'L') lst[i][j] = 3;
			g[i * m + j] = i * m + j;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			//cout << i << " " << j << " " << g[i * m + j] << "\n";
			if (g[i * m + j] == i * m + j) {
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int g = Find(i * m + j);
			//cout << i * m + j << " " << g << "\n";
			dic.insert(g);
		}
	}
	cout << dic.size();
}