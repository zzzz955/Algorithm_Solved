#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 100;
int n, m, ans;
bool v[N];

bool bfs(int sn, const vector<vector<int>>& edges) {
	queue<int> q;
	q.push(sn);
	int front = 0;
	v[sn] = true;

	while (!q.empty()) {
		int cn = q.front(); q.pop();

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			front++;
			q.push(nn);
		}
	}

	//cout << sn << " " << front << "\n";
	return front > n / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> asc(n + 1), desc(n + 1);
	while (m--) {
		int a, b; cin >> a >> b;
		asc[a].push_back(b);
		desc[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		memset(v, 0, sizeof(v));
		if (bfs(i, asc)) {
			ans++;
			continue;
		}

		memset(v, 0, sizeof(v));
		if (bfs(i, desc)) {
			ans++;
			continue;
		}
	}

	cout << ans;
}