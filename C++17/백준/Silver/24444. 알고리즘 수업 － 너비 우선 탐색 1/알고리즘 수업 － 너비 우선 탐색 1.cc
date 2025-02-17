#include<iostream>
#include<queue>
#include<set>
using namespace std;

const int N = 100001;
int n, m, r;
int it[N];
bool v[N];
set<int> lst[N];

void bfs() {
	queue<int> q;
	q.push(r);
	int t = 1;
	it[r] = t++;
	v[r] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i : lst[cur]) {
			if (v[i]) continue;
			v[i] = true;
			it[i] = t++;
			q.push(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;
	while (m--) {
		int a, b; cin >> a >> b;
		lst[a].insert(b);
		lst[b].insert(a);
	}
	bfs();
	for (int i = 1; i <= n; ++i) cout << it[i] << "\n";
}