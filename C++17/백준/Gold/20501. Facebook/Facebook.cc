#include<iostream>
#define ull unsigned long long
using namespace std;

const int N = 2000;
const int B = 32;
int n, q;
ull bits[N][B];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char ch; cin >> ch;
			if (ch == '1') bits[i][j / 64] |= 1ull << (j % 64);
		}
	}
	
	cin >> q;
	int m = n % 64 ? n / 64+ 1 : n / 64;
	while (q--) {
		int a, b; cin >> a >> b;
		int ans = 0;
		--a; --b;
		for (int i = 0; i < m; ++i) {
			ans += __builtin_popcountll(bits[a][i] & bits[b][i]);
		}
		cout << ans << "\n";
	}
}