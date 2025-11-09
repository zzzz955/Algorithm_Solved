#include<iostream>
using namespace std;

const int N = 1e5;
int t, n, m, k;
int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		int total = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			total += a[i];
		}

		if (n == m) {
			cout << (total < k ? 1 : 0) << "\n";
			continue;
		}

		int sum = 0;
		for (int i = 0; i < m; ++i) sum += a[i];
		int cnt = sum < k ? 1 : 0;

		for (int i = 0; i < n - 1; ++i) {
			sum -= a[i];
			int f = i + m >= n ? i + m - n : i + m;
			sum += a[f];

			if (sum < k) ++cnt;
		}
		cout << cnt << "\n";
	}
}