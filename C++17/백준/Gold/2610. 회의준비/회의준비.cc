#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<set>
#include<cstring>
using namespace std;

const int N = 101;
int n, m;
bool v[N];
vector<int> edges[N];
unordered_map<int, vector<int>> g;
struct Pos {
	int cn, cv;
};

void bfs(int sn, int c) {
	queue<int> q;
	q.push(sn);
	v[sn] = true;
	vector<int> group(1, sn);

	while (!q.empty()) {
		int cn = q.front(); q.pop();

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			q.push(nn);
			group.push_back(nn);
		}
	}

	g[c] = group;
}

int get_dist(int sn, int cd) {
	queue<Pos> q;
	q.push({ sn, 0 });
	memset(v, 0, sizeof(v));
	v[sn] = true;
	int md = 0;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cn = pos.cn, cv = pos.cv;
		if (cd == cv) return cv;
		if (md < cv) md = cv;

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			q.push({ nn, cv + 1 });
		}
	}

	return md;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int c = 0;
	for (int i = 1; i <= n; ++i) {
		if (v[i]) continue;
		bfs(i, ++c);
	}

	set<int> ans;
	for (const auto& d : g) {
		int h = -1, md = 2e9;
		for (int sn : d.second) {
			int d = get_dist(sn, md);
			if (d < md) {
				md = d;
				h = sn;
			}
		}
		ans.insert(h);
	}

	cout << g.size() << "\n";
	for (int i : ans) cout << i << "\n";
}