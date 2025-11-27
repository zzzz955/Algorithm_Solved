#include<iostream>
using namespace std;

const int N = 1e6;
int s[N];
int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> s[i];

	int l = 0, r = 0, c = 0, len = 0, ans = 0;
	while (r < n) {
		if (s[r] % 2) ++c;
		else ++len;
		
		while (c > k) {
			if (s[l] % 2) --c;
			else --len;
			++l;
		}

		ans = max(ans, len);
		++r;
	}
	cout << ans;
}