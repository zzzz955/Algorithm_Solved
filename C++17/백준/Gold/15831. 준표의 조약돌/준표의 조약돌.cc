#include<iostream>
using namespace std;

const int N = 3e5;
int n, b, w;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b >> w >> s;
	int l = 0, r = 0;
	int cb = s[r] == 'W' ? 0 : 1;
	int cw = s[r] == 'W' ? 1 : 0;

	int mx = cb <= b && cw >= w ? 1 : 0;
	while (++r < n) {
		if (s[r] == 'W') ++cw;
		else ++cb;

		while (cb > b) {
			if (s[l] == 'B') --cb;
			else --cw;
			++l;
		}

		if (cb <= b && cw >= w) mx = max(mx, r - l + 1);
	}
	cout << mx;
}