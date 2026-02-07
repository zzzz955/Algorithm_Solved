#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e4 + 1;
int n, m;
vector<int> edges[N];
bool v[N];
struct Pos {
	int cn, t;
};

int bfs(int f, int t) {
	queue<Pos> q;
	q.push({f, 0});
	v[f] = true;
	int dist = 0;
	vector<int> path(n + 1, 0);

	while (!q.empty()) {
		auto [cn, ct] = q.front(); q.pop();
		if (cn == t) break;

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			path[nn] = cn;
			q.push({ nn, ct + 1 });
		}
	}

	memset(v, false, sizeof(v));
	int cn = t;
	while (cn != f) {
		++dist;
		cn = path[cn];
		v[cn] = true;
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int f, t; cin >> f >> t;
		edges[f].push_back(t);
		edges[t].push_back(f);
	}

	for (int i = 1; i <= n; ++i) {
		sort(edges[i].begin(), edges[i].end());
	}

	int f, t; cin >> f >> t;
	int dist = bfs(f, t);
	v[f] = false;
	dist += bfs(t, f);
	cout << dist;
}