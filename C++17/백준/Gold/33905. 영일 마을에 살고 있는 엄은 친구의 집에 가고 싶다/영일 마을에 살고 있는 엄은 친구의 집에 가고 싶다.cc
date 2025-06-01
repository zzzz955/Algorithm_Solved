#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 5005;
int n, m, k;
bool v[N];
vector<int> edges[N];

void bfs() {
	queue<int> q;
	q.push(1);
	v[1] = true;
	int cnt = 0;

	while (!q.empty()) {
		int cn = q.front(); q.pop();

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			cnt++;
			v[nn] = true;
			q.push(nn);
		}
	}
	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (m--) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	while (k--) {
		int a; cin >> a;
		v[a] = true;
	}

	bfs();
}