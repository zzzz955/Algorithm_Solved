#include<iostream>
using namespace std;

const int N = 101;
int n, m;
bool d[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		d[a][b] = true;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (!d[i][k] || !d[k][j]) continue;
				d[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		int cnt = 0;

		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (!d[i][j] && !d[j][i]) ++cnt;
		}

		cout << cnt << "\n";
	}
}