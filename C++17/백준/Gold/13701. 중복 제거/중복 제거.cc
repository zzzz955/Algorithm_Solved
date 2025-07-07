#include<iostream>
using namespace std;

char bucket[(1 << 25) / 8];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	while (cin >> n) {
		int idx = n / 8;
		int mod = n % 8;
		if (bucket[idx] & (1 << mod)) continue;
		bucket[idx] += (1 << mod);
		cout << n << " ";
	}
}