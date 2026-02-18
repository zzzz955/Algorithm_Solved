#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

const int N = 501;
int n, m, q;
unordered_set<int> edges[N];
struct Pos {
	int cn, ct;
};

void bfs() {
	queue<Pos> ps;
	ps.push({ 1, 0 });
	vector<int> dist(n + 1, -1);
	dist[1] = 0;

	while (!ps.empty()) {
		auto [cn, ct] = ps.front(); ps.pop();

		for (int nn : edges[cn]) {
			if (dist[nn] != -1) continue;
			dist[nn] = ct + 1;
			ps.push({ nn, ct + 1 });
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << dist[i] << (i != n ? " " : "");
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int f, ct; cin >> f >> ct;
		edges[f].insert(ct);
		edges[ct].insert(f);
	}

	cin >> q;
	while (q--) {
		int o, f, ct; cin >> o >> f >> ct;
		if (o == 1) {
			edges[f].insert(ct);
			edges[ct].insert(f);
		}
		else {
			edges[f].erase(ct);
			edges[ct].erase(f);
		}

		bfs();
	}
}