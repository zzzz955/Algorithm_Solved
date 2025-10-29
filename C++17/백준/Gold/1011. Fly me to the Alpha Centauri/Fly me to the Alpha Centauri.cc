#include<iostream>
using namespace std;

int t;

int main() {
	cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
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