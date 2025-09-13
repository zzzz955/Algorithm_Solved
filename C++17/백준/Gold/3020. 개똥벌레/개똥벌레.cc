#include<iostream>
using namespace std;

const int N = 5e5 + 2;
int n, h;
int d[N];
int p[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		if (i % 2) {
			d[1]++;
			d[a + 1]--;
		}
		else d[h - a + 1]++;
	}

	int ans = 2e9, cnt = 1;
	for (int i = 1; i <= h; ++i) {
		p[i] = p[i - 1] + d[i];
		if (p[i] < ans) {
			ans = p[i];
			cnt = 1;
		}
		else if (p[i] == ans) cnt++;
	}
	//for (int i = 1; i <= h; ++i) cout << d[i] << " ";
	//cout << "\n";
	//for (int i = 1; i <= h; ++i) cout << p[i] << " ";
	cout << ans << " " << cnt;
}