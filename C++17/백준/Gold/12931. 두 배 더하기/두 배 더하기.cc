#include<iostream>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int md = 0, mc = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;

		int d = 0;
		while (x > 0) {
			if (x % 2) {
				--x;
				++mc;
			}
			else {
				x /= 2;
				++d;
			}
		}

		md = max(md, d);
	}
	cout << mc + md;
}