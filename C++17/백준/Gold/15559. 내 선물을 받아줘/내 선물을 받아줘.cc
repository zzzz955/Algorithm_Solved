#include<iostream>
#include<queue>
using namespace std;

int n, m, ans;
int lst[1000][1000];
int g[1000][1000];
int G, B;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void dfs(int x, int y) {
	if (g[x][y] == G) return;
	if (g[x][y] && g[x][y] < G) {
		B = g[x][y];
		ans--;
		return;
	}

	int nx = x + dx[lst[x][y]], ny = y + dy[lst[x][y]];
	g[x][y] = G;
	dfs(nx, ny);
	g[x][y] = B;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'N') lst[i][j] = 0;
			else if (s[j] == 'W') lst[i][j] = 1;
			else if (s[j] == 'E') lst[i][j] = 2;
			else lst[i][j] = 3;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!g[i][j]) {
				B = ++G;
				ans++;
				dfs(i, j);
			}
		}
	}

	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		cout << g[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	cout << ans;
}