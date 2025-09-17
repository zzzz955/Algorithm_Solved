#include<iostream>
using namespace std;
using ull = unsigned long long;

int main() {
	ull x, k, y = 0; cin >> x >> k;
	int i = 0, j = 0;

	while ((k >> j) > 0 || (x >> i) > 0) {
		if (!((x >> i) & 1)) {
			if (((k >> j) & 1)) y |= ((ull)1 << i);
			j++;
		}
		i++;
	}
	cout << y;
}

//65535 1000000000
//65536000000000

//65535 2000000000
//131072000000000

//1073741823 2000000000
//2147483648000000000