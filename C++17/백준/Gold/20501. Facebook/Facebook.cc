#include<iostream>
using namespace std;

const int N = 2000;
const int B = 250;
int n, q;
char bits[N][B];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char ch; cin >> ch;
			if (ch == '1') bits[i][j / 8] |= 1 << (j % 8);
		}
	}
	
	cin >> q;
	int m = n % 8 ? n / 8 + 1 : n / 8;
	while (q--) {
		int a, b; cin >> a >> b;
		int ans = 0;
		--a; --b;
		for (int i = 0; i < m; ++i) {
			char res = bits[a][i] & bits[b][i];
			for (int j = 0; j < 8; ++j) {
				if (res & (1 << j)) ans++;
			}
		}
		cout << ans << "\n";
	}
}