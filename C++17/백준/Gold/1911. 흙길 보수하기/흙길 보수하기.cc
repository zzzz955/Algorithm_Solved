#include<iostream>
#include<queue>
#define pii pair<int, int>
using namespace std;

int n, l;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < n; ++i) {
		int s, e; cin >> s >> e;
		pq.push({ s, e });
	}

	int c = pq.top().first;
	int ans = 0;
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		int s = cur.first, e = cur.second;

		if (c >= e) continue;
		c = max(c, s);
		int diff = e - c;
		int div = diff / l;
		bool mod = diff % l ? true : false;
		if (mod) div++;
		ans += div;
		c += div * l;
	}
	cout << ans;
}