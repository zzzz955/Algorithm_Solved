#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 1;
int n, m, x;
vector<int> asc[N];
vector<int> desc[N];
bool v[N];

int bfs(bool flag) {
	queue<int> q;
	q.push(x);
	memset(v, 0, sizeof(v));
	v[x] = true;
	int cnt = 0;

	while (!q.empty()) {
		int cn = q.front(); q.pop();

		for (int nn : flag ? desc[cn] : asc[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			cnt++;
			q.push(nn);
		}
	}

	return flag ? n - cnt : 1 + cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;
	while (m--) {
		int a, b; cin >> a >> b;
		desc[a].push_back(b);
		asc[b].push_back(a);
	}

	cout << bfs(false) << " " << bfs(true);
}