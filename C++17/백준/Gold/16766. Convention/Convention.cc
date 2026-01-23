#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5;
int n, m, c;
int arr[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> c;
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (r < arr[i]) r = arr[i];
	}
	sort(arr, arr + n);

	int ans = 2e9;
	while (l <= r) {
		int mid = (l + r) / 2;
		int arrive = arr[0];
		int cnt = 1;
		int in_bus = 1;
		int mx = 0;

		for (int i = 1; i < n; ++i) {
			if (cnt > m) break;
			if (arrive + mid < arr[i] || in_bus >= c) {
				mx = max(mx, arr[i - 1] - arrive);
				in_bus = 1;
				arrive = arr[i];
				++cnt;
				continue;
			}
			++in_bus;
		}
		mx = max(mx, arr[n - 1] - arrive);

		if (cnt > m) l = mid + 1;
		else {
			ans = min(ans, mx);
			r = mid - 1;
		}
	}
	cout << ans;
}