#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;

const int N = 2e5 + 1;
int n, m;
int lst[N];
int cnt[N];
int conn[N];
bool v[N];
vector<int> edges[N];
queue<int> q;

void bfs() {
	int ct = 0;
	while (!q.empty() && ++ct) {
		queue<int> q2;
		swap(q, q2);
		unordered_set<int> visit;

		while (!q2.empty()) {
			int cn = q2.front(); q2.pop();

			for (int nn : edges[cn]) {
				if (v[nn]) continue;
				visit.insert(nn);
				cnt[nn]++;
			}
		}

		for (int i : visit) {
			int m_visit = conn[i] % 2 ? conn[i] / 2 + 1 : conn[i] / 2;
			if (cnt[i] >= m_visit) {
				v[i] = true;
				lst[i] = ct;
				q.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		while (1) {
			int a; cin >> a;
			if (!a) break;
			edges[i].push_back(a);
		}
	}

	for (int i = 1; i <= n; ++i) conn[i] = edges[i].size();

	memset(lst, -1, sizeof(lst));
	cin >> m;
	while (m--) {
		int a; cin >> a;
		lst[a] = 0;
		q.push(a);
		v[a] = true;
	}

	bfs();

	for (int i = 1; i <= n; ++i) cout << lst[i] << " ";
}