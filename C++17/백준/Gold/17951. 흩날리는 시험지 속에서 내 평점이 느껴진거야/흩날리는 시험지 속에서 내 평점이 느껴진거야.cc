#include<iostream>
using namespace std;

const int N = 1e5;
int n, k;
int lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int r = 0;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		r += lst[i];
	}

	int l = 0, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;

		int sum = 0, cnt = 0;
		for (int i = 0; i < n; ++i) {
			sum += lst[i];
			if (sum >= mid) {
				++cnt;
				sum = 0;
			}
		}

		if (cnt >= k) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}