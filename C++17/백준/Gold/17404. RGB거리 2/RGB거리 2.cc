#include<iostream>
using namespace std;

const int N = 1e3;
int n;
int lst[N][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> lst[i][j];

	int ans = 2e9;
	for (int i = 0; i < 3; ++i) {
		int r = i == 0 ? lst[0][0] : 2e9;
		int g = i == 1 ? lst[0][1] : 2e9;
		int b = i == 2 ? lst[0][2] : 2e9;

		for (int i = 1; i < n; ++i) {
			int nr = min(g, b) + lst[i][0];
			int ng = min(r, b) + lst[i][1];
			int nb = min(r, g) + lst[i][2];
			r = nr, g = ng, b = nb;
		}

		if (i != 0) ans = min(ans, r);
		if (i != 1) ans = min(ans, g);
		if (i != 2) ans = min(ans, b);
	}
	cout << ans;
}