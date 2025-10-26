#include<iostream>
using namespace std;

const int N = 3e6;
const int D = 3e3 + 1;
int n, d, k, c;
int lst[N];
int dic[D];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	int uniq = 0;
	for (int i = 0; i < k; ++i) if (++dic[lst[i]] == 1) ++uniq;
	int ans = uniq + (dic[c] > 0 ? 0 : 1);

	int L = 0, R = k;
	for (int i = 0; i < n; ++i) {
		int del = lst[L];
		if (--dic[del] == 0) --uniq;
		if (++L == n) L = 0;

		int add = lst[R];
		if (++dic[add] == 1) ++uniq;
		if (++R == n) R = 0;

		int cnt = uniq + (dic[c] > 0 ? 0 : 1);
		if (ans < cnt) ans = cnt;
	}
	cout << ans;
}