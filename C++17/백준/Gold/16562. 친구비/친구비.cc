#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 10001;
int n, m, k;
int cost[N];
bool v[N];
vector<int> edges[N];

int bfs(int sn) {
	queue<int> q;
	q.push(sn);
	int mn = cost[sn];
	v[sn] = true;

	while (!q.empty()) {
		int cn = q.front(); q.pop();

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			mn = min(mn, cost[nn]);
			q.push(nn);
		}
	}
	return mn;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> cost[i];
	
	while (m--) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (v[i]) continue;
		sum += bfs(i);
	}
	
	if (sum > k) cout << "Oh no";
	else cout << sum;
}