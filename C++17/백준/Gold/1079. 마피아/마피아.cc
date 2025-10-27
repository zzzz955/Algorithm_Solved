#include<iostream>
using namespace std;

const int N = 16;
int n, m, ans;
int p[N];
int lst[N][N];
bool die[N];

void bt(int remain, int day) {
	if (remain % 2 == 0) {
		ans = max(ans, day);
		for (int i = 0; i < n; ++i) {
			if (i == m) continue;
			if (die[i]) continue;
			die[i] = true;
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				if (die[j]) continue;
				p[j] += lst[i][j];
			}
			bt(remain - 1, day);
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				if (die[j]) continue;
				p[j] -= lst[i][j];
			}
			die[i] = false;
		}
	}
	else {
		int mx = -1e9, idx = 0;
		for (int i = 0; i < n; ++i) {
			if (die[i]) continue;
			if (p[i] > mx) {
				mx = p[i];
				idx = i;
			}
		}

		if (idx == m) return;
		die[idx] = true;
		bt(remain - 1, day + 1);
		die[idx] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> p[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> lst[i][j];
	cin >> m;

	bt(n, n % 2 ? 0 : 1);
	cout << ans;
}