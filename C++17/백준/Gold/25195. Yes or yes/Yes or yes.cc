#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1e5 + 1;
int n, m, s;
bool sp[N];
bool fv[N];
vector<int> edges[N];

bool bfs(int sn) {
	queue<int> q;
	q.push(sn);
	vector<bool> v(n + 1, false);
	v[sn] = true;

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		if (cn == 1) return true;

		for (int nn : edges[cn]) {
			if (v[nn] || fv[nn]) continue;
			v[nn] = true;
			q.push(nn);
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		sp[a] = true;
		edges[b].push_back(a);
	}

	cin >> s;
	while (s--) {
		int a; cin >> a;
		fv[a] = true;
	}

	for (int i = 1; i <= n; ++i) {
		if (sp[i]) continue;
		if (fv[i]) continue;
		if (bfs(i)) {
			cout << "yes";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}