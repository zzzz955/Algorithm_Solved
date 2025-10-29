#include<iostream>
#include<queue>
using namespace std;

const int N = 1e4;
int n, ans;
struct Station {
	int x, c;
	bool operator<(const Station& other) const {
		return x > other.x;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<Station> pq1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, c; cin >> x >> c;
		pq1.push({ x, c });
	}

	priority_queue<int> pq2;
	int l, p; cin >> l >> p;
	while (!pq1.empty() && pq1.top().x <= p) {
		pq2.push(pq1.top().c);
		pq1.pop();
	}

	while (p < l && !pq2.empty()) {
		ans++;
		p += pq2.top();
		pq2.pop();

		while (!pq1.empty() && pq1.top().x <= p) {
			pq2.push(pq1.top().c);
			pq1.pop();
		}
	}

	cout << (p < l ? -1 : ans);
}