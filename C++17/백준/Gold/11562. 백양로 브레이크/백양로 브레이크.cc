#include<iostream>
#include<vector>
using namespace std;

int n, m, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 2e9));
	while (m--) {
		int u, v, e; cin >> u >> v >> e;
		if (!e) {
			dist[u][v] = 0;
			dist[v][u] = 1;
		}
		else {
			dist[u][v] = 0;
			dist[v][u] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) dist[i][i] = 0;

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][k] != 2e9 && dist[k][j] != 2e9) {
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
	}

	cin >> k;
	while (k--) {
		int sn, dn; cin >> sn >> dn;
		cout << dist[sn][dn] << "\n";
	}
}