#include<iostream>
using namespace std;

string a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	int n = a.size(), m = b.size();
	for (int i = 0; i < n; ++i) {
		c += a[i];

		if (c.size() >= b.size()) {
			int len = 0;
			int idx = c.size() - 1;

			for (int j = m - 1; j >= 0; --j) {
				if (c[idx] == b[j]) {
					++len;
					--idx;
				}
				if (len == m) {
					while (len--) c.pop_back();
					break;
				}
			}

		}
	}
	cout << c;
}