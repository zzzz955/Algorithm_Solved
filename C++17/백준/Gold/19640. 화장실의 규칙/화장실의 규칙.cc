#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, k;
struct Prio {
	int d, h, qi, id;
	bool operator<(const Prio& other) const {
		if (d == other.d && h == other.h) return qi > other.qi;
		if (d == other.d) return h < other.h;
		return d < other.d;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	vector<queue<Prio>> q(m);

	int idx = 0;
	for (int i = 0; i < n; ++i) {
		int d, h; cin >> d >> h;

		q[idx].push({ d, h, idx, i });
		if (++idx == m) idx = 0;
	}

	priority_queue<Prio> pq;
	for (int i = 0; i < m; ++i) {
		if (q[i].empty()) continue;
		pq.push(q[i].front());
		q[i].pop();
	}

	int cnt = 0;
	while (!pq.empty()) {
		Prio prio = pq.top(); pq.pop();
		int d = prio.d, h = prio.h, qi = prio.qi, id = prio.id;

		if (id == k) {
			cout << cnt;
			return 0;
		}

		++cnt;
		if (!q[qi].empty()) {
			pq.push(q[qi].front());
			q[qi].pop();
		}
	}
}