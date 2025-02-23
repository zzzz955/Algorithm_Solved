#include<iostream>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	int cnt = 0, ans = 0;
	for (int i = 31; i >= 0; --i) {
		if (n & (1 << i)) {
			n -= (1 << i);
			cnt++;
			if (cnt == k && n) {
				ans = (1 << i) - n;
				break;
			}
		}
	}
	cout << ans;
}