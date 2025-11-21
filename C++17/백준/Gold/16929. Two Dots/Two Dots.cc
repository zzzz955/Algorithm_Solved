#include<iostream>
using namespace std;

const int N = 50;
string s[N];
int n, m;
int v[N][N];
int t;
bool cycle;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int cx, int cy, const char& ch, int t) {
	if (cycle) return;

	for (int i = 0; i < 4; ++i) {
		int nx = cx + dx[i], ny = cy + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] == ch) {
			if (!v[nx][ny]) {
				v[nx][ny] = t + 1;
				dfs(nx, ny, ch, t + 1);
			}
			if (v[nx][ny]) {
				if (abs(v[nx][ny] - t) < 2) continue;
				else {
					cycle = true;
					return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> s[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j]) continue;
			v[i][j] = 1;
			dfs(i, j, s[i][j], 1);
			if (cycle) break;
		}
	}
	cout << (cycle ? "Yes" : "No");
}