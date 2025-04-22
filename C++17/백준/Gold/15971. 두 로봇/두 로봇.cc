#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 100001;
int n, r1, r2;
bool v[N];
struct Edge {
	int nn, nv;
};
vector<Edge> edges[N];
struct Pos {
	int cn, cv, mv;
};

int dijkstra() {
	queue<Pos> q;
	q.push({ r1, 0, 0 });
	v[r1] = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cn = pos.cn, cv = pos.cv, mv = pos.mv;
		if (cn == r2) return cv - mv;
		//cout << "cn: " << cn << "\n";

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = edge.nv;
			if (v[nn]) continue;
			v[nn] = true;
			q.push({ nn, cv + nv, max(mv, nv)});
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r1 >> r2;
	int m = n - 1;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	cout << dijkstra();
}