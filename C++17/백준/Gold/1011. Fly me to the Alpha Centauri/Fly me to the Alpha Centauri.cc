#include<iostream>
using namespace std;

int t, x, y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (y - x == 1) {
			cout << 1 << "\n";
			continue;
		}

		int move = 0;
		int dist = 1;
		while (x < y) {
			x += dist;
			++move;
			if (x >= y) break;

			y -= dist;
			++move;
			if (x >= y) break;

			++dist;
		}
		cout << move << "\n";
	}
}