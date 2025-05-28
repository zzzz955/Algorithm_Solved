#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1001;
int n, l;
string H[N];
int c[N];
bool v[N];
vector<int> edges[N];

vector<int> bfs(int sn, int en) {
	queue<int> q;
	q.push(sn);
	v[sn] = true;

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		if (cn == en) break;

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			c[nn] = cn;
			q.push(nn);
		}
	}

	if (!v[en]) return {};

	vector<int> path(1, en);
	while (en != sn) {
		en = c[en];
		path.push_back(en);
	}
	return path;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l;
	for (int i = 1; i <= n; ++i) cin >> H[i];

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int cnt = 0;

			//cout << H[i].size() << " " << H[j].size() << "\n";
			for (int k = 0; k < l; ++k) {
				if (H[i][k] != H[j][k]) cnt++;
				if (cnt >= 2) break;
			}

			if (cnt == 1) {
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}

	int sn, en; cin >> sn >> en;
	vector<int> res = bfs(sn, en);

	if (res.empty()) cout << -1;
	else {
		reverse(res.begin(), res.end());
		for (int i : res) cout << i << " ";
	}
}