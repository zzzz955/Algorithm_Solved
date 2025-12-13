#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;

const int N = 1e6;
int n;
pii a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s, t; cin >> s >> t;
		a[i] = { s, t };
	}
	sort(a, a + n);

	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i) {
		pii d = a[i];

		while (!pq.empty() && pq.top() <= d.first) pq.pop();
		pq.push(d.second);

		ans = max(ans, (int)pq.size());
	}
	cout << ans;
}