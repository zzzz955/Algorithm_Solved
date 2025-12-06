#include<iostream>
#include<queue>
using namespace std;
using ll = long long;

const int N = 2e5;
int n, g, k;
priority_queue<ll, vector<ll>, greater<ll>> pq;
struct Info {
	int S, L;
	bool O;
};
Info ing[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> g >> k;
	for (int i = 0; i < n; ++i) {
		int S, L;
		bool O;
		cin >> S >> L >> O;
		ing[i] = { S, L, O };
	}

	ll l = 0, r = 2e9, ans = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll sum = 0;
		int remove = 0;

		for (int i = 0; i < n; ++i) {
			const Info& info = ing[i];
			ll val = 1ll * info.S * max(1ll, mid - info.L);
			sum += val;

			if (info.O) {
				pq.push(val);
				if (pq.size() > k) pq.pop();
			}
		}

		while (!pq.empty()) {
			ll val = pq.top(); pq.pop();
			sum -= val;
		}

		//cout << sum << "\n";
		if (sum <= g) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}