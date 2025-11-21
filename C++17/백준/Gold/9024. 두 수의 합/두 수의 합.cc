#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6;
int t, n, k;
int s[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) cin >> s[i];
		sort(s, s + n);

		int b = 2e9, cnt = 0;
		int l = 0, r = n - 1;
		while (l < r) {
			int sum = s[l] + s[r];
			int diff = abs(k - sum);

			if (b > diff) {
				b = diff;
				cnt = 1;
			}
			else if (b == diff) ++cnt;
			
			if (sum < k) ++l;
			else if (sum > k) --r;
			else {
				--r;
				++l;
			}
		}
		cout << cnt << "\n";
	}
	
}