#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e4;
int n;
int lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	sort(lst, lst + n);

	long long ans = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			int two = lst[i] + lst[j];
			auto ut = upper_bound(lst + j + 1, lst + n, -two);
			auto lt = lower_bound(lst + j + 1, lst + n, -two);
			ans += ut - lt;
		}
	}

	cout << ans;
}