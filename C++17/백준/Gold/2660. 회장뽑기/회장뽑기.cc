#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int N = 51;
int n;
vector<int> edges[N];
bool v[N];
struct Pos {
	int cn, cv;
};

int bfs(int sn) {
	queue<Pos> q;
	q.push({ sn, 0 });
	v[sn] = true;
	int mv = 0;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cn = pos.cn, cv = pos.cv;
		if (mv < cv) mv = cv;

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			q.push({ nn, cv + 1 });
		}
	}

	return mv;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (1) {
		int a, b; cin >> a >> b;
		if (a == -1 && b == -1) break;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int mv = 2e9;
	vector<int> lst;
	for (int i = 1; i <= n; ++i) {
		memset(v, 0, sizeof(v));
		int res = bfs(i);

		if (res < mv) {
			mv = res;
			lst.clear();
			lst.push_back(i);
		}
		else if (res == mv) lst.push_back(i);
	}

	cout << mv << " " << lst.size() << "\n";
	for (int i : lst) cout << i << " ";
}