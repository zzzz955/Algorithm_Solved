#include<iostream>
#include<queue>
#define ll long long
using namespace std;

const int N = 1e6;
int t, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0; i < n; ++i) {
			int a; cin >> a;
			pq.push(a);
		}

		ll ans = 0;
		while (pq.size() != 1) {
			ll n1 = pq.top(); pq.pop();
			ll n2 = pq.top(); pq.pop();
			pq.push(n1 + n2);
			ans += n1 + n2;
		}
		cout << ans << "\n";
	}
}