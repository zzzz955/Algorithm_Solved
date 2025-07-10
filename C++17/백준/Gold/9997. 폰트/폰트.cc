#include<iostream>
using namespace std;

const int N = 25;
int n, tar;
long long ans;
int lst[N];

void bt(int idx, int bit) {
	if (idx >= n) {
		if (bit == tar) {
			ans++;
		}
		return;
	}
	bt(idx + 1, bit | lst[idx]);
	bt(idx + 1, bit);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int b = 0;
		for (const char& c : s) {
			b |= 1 << c - 'a';
		}
		lst[i] = b;
	}

	tar = (1 << 26) - 1;
	bt(0, 0);
	cout << ans;
}