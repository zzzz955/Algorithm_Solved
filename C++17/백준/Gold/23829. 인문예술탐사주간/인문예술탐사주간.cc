#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
int arr[N];
ll pre_sum[N];
int n, q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		arr[i] = x;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) pre_sum[i] = i == 0 ? arr[i] : pre_sum[i - 1] + arr[i];

	while (q--) {
		int x; cin >> x;

		int idx = lower_bound(arr, arr + n, x) - arr;
		ll L_sum = idx == 0 ? 0 : pre_sum[idx - 1];
		ll R_sum = pre_sum[n - 1] - L_sum;

		ll L = 1ll * x * idx - L_sum;
		ll R = R_sum - 1ll * x * (n - idx);		
		cout << L + R << "\n";
	}
}