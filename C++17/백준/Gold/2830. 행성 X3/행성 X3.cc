#include<iostream>
#define ll long long
using namespace std;

const int N = 1e6;
int n;
int lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	ll ans = 0;
	for (int i = 0; i < 20; ++i) {
		ll bit0 = 0, bit1 = 0;

		for (int j = 0; j < n; ++j) {
			if (lst[j] & 1 << i) bit1++;
			else bit0++;
		}

		ans += (1ll << i) * bit1 * bit0;
	}
	cout << ans;
}