#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define pii pair<int, int>
using namespace std;

const int N = 1001;
int t, n, m;
vector<int> edges[N];
int colors[N];

bool bfs(int snode) {
	queue<pii> q;
	q.push({ snode, 0 });
	colors[snode] = 0;

	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		int cn = cur.first, cc = cur.second;
		//cout << "cn: " << cn << "cc: " << cc << "\n";

		for (int nn : edges[cn]) {
			if (colors[nn] == cc) return false;
			if (colors[nn] == -1) {
				colors[nn] = cc ^ 1;
				q.push({ nn, cc ^ 1 });
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) edges[i].clear();

		while (m--) {
			int a, b; cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		memset(colors, -1, sizeof(colors));
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			if (colors[i] != -1) continue;
			if (!bfs(i)) {
				flag = false;
				break;
			}
		}

		if (flag) cout << "possible\n";
		else cout << "impossible\n";
	}
}