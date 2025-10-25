#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
struct Town {
	int x, p;
	bool operator<(const Town& other) const {
		return x < other.x;
	}
};
int n;
Town towns[N];
ll presum[N + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, p; cin >> x >> p;
		towns[i] = { x, p };
	}

	sort(towns, towns + n);
	for (int i = 1; i <= n; ++i) presum[i] = presum[i - 1] + towns[i - 1].p;
	ll total = presum[n];
	//cout << total << "\n";

	int l = 0, r = n, x = 1e9;
	while (l <= r) {
		int mid = (l + r) / 2;
		ll dist = presum[mid];
		//cout << mid << " " << presum[mid] << "\n";

		if (dist >= (total + 1) / 2) {
			r = mid - 1;
			x = mid;
		}
		else l = mid + 1;
	}
	cout << towns[x - 1].x;
}