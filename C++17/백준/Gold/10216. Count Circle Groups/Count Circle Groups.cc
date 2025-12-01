#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

const int N = 3e3 + 1;
int t, n;
struct Pos {
	int x, y, r;
};
Pos poses[N];
vector<int> edges[N];
bool v[N];

double get_dist(const Pos& a, const Pos& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void bfs(int sn) {
	queue<int> q;
	q.push(sn);
	v[sn] = true;

	while (!q.empty()) {
		int cn = q.front(); q.pop();

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			q.push(nn);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; ++i) {
			int x, y, r; cin >> x >> y >> r;
			poses[i] = { x, y, r };
		}

		for (int i = 1; i <= n; ++i) edges[i].clear();
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				Pos a = poses[i], b = poses[j];
				double dist = get_dist(a, b);
				if (dist <= poses[i].r + poses[j].r) {
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
		}

		int g = 0;
		memset(v, 0, n + 1);
		for (int i = 1; i <= n; ++i) {
			if (v[i]) continue;
			++g;
			bfs(i);
		}

		cout << g << "\n";
	}
}