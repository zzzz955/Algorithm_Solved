#include<iostream>
using namespace std;

const int N = 1e6 + 1;
int cnt[N];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int h; cin >> h;
		if (cnt[h + 1]) {
			--cnt[h + 1];
			++cnt[h];
		}
		else {
			++cnt[h];
			ans++;
		}
	}
	cout << ans;
}