#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 2e3 + 1;
int n, m, q;
int v[N];
vector<int> edges[N];

vector<int> bfs(int sn) {
	queue<int> q;
	q.push(sn);
	vector<int> dist(n + 1, -1);
	dist[sn] = 0;

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		//cout << "cn : " << cn << "\n";

		for (int nn : edges[cn]) {
			if (dist[nn] == -1) {
				dist[nn] = dist[cn] + 1;
				q.push(nn);
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> q;
	while (m--) {
		int u, v; cin >> u >> v;
		edges[v].push_back(u);
	}

	while (q--) {
		int u, v; cin >> u >> v;
		vector<int> u_dist = bfs(u);
		vector<int> v_dist = bfs(v);

		int res = 2e9;
		for (int i = 1; i <= n; ++i) {
			//cout << "i : " << i << " " << u_dist[i] << " " << v_dist[i] << "\n";
			if (u_dist[i] == -1) continue;
			if (v_dist[i] == -1) continue;
			res = min(res, max(u_dist[i], v_dist[i]));
		}
		int ans = res == 2e9 ? -1 : res;
		cout << ans << "\n";
	}
}