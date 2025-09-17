#include<iostream>
using namespace std;
using ll = long long;

ll x, k, y, i, j;

int main() {
	cin >> x >> k;
	while ((k >> j) > 0 || (x >> i) > 0) {
		if (!((x >> i) & 1)) {
			if (((k >> j) & 1)) y |= ((ll)1 << i);
			j++;
		}
		i++;
	}
	cout << y;
}