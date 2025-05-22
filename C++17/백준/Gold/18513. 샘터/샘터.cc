#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

const int MX = -1e8;
const int MN = 1e8;
int n, k;
long long ans;
int dx[] = { -1, 1 };
struct PD {
	int p, d;
};
queue<PD> q;
unordered_set<int> v;

void bfs() {
	while (!q.empty()) {
		PD pd = q.front(); q.pop();
		int p = pd.p, d = pd.d;

		for (int i = 0; i < 2; ++i) {
			int np = p + dx[i], nd = d + 1;
			if (!v.count(np)) {
				v.insert(np);
				ans += nd;
				q.push({ np, nd });
				if (!--k) return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		v.insert(x);
		q.push({ x, 0 });
	}

	bfs();
	cout << ans;
}