#include<iostream>
using namespace std;

const int N = 1e5;
int t[N];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> t[i];

	int l = 0, r = n - 1;
	int mx = 0;
	while (l < r) {
		int le = t[l], re = t[r];
		int len = r - l - 1;
		mx = max(mx, len * min(le, re));

		if (le > re) --r;
		else if (le < re) ++l;
		else {
			--r;
			++l;
		}
	}
	cout << mx;
}