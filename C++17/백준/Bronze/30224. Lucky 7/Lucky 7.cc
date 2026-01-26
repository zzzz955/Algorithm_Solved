#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int c = n;
	bool f1 = n % 7 ? false : true;
	bool f2 = false;
	while (c) {
		if (c % 10 == 7) {
			f2 = true;
			break;
		}
		c /= 10;
	}

	if (!f1 && !f2) cout << 0;
	if (f1 && !f2) cout << 1;
	if (!f1 && f2) cout << 2;
	if (f1 && f2) cout << 3;
}