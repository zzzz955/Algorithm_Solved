#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
using ll = long long;

ll l, n;
int k, cnt;
queue<ll> q;
priority_queue<int, vector<int>, greater<int>> pq;
unordered_map<ll, int> v;

void bfs() {
	while (!q.empty() && cnt <= k) {
		ll cur = q.front(); q.pop();
		
		ll prev = cur - 1;
		ll next = cur + 1;
		if (prev >= 0 && !v.count(prev)) {
			q.push(prev);
			v[prev] = v[cur] + 1;
			cnt++;
			pq.push(v[prev]);
		}

		if (next <= l && !v.count(next)) {
			q.push(next);
			v[next] = v[cur] + 1;
			cnt++;
			pq.push(v[next]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> l >> n >> k;
	while (n--) {
		ll a; cin >> a;
		q.push(a);
		v[a] = 0;
		cnt++;
		pq.push(v[a]);
	}

	bfs();
	while (!pq.empty() && k--) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}