#include<iostream>
using namespace std;

const int V = 401;
int dist[V][V];
int v, e;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; ++i)
		for (int j = 1; j <= v; ++j)
			dist[i][j] = i == j ? 0 : 1e9;

	while (e--) {
		int f, t, w; cin >> f >> t >> w;
		dist[f][t] = w;
	}
	for (int k = 1; k <= v; ++k) {
		for (int i = 1; i <= v; ++i) {
			for (int j = 1; j <= v; ++j) {
				if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int mn = 1e9;
	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			if (i == j) continue;
			if (dist[i][j] == 2e9 || dist[j][i] == 2e9) continue;
			mn = min(mn, dist[i][j] + dist[j][i]);
		}
	}
	cout << (mn == 1e9 ? -1 : mn);
}