#include<iostream>
using namespace std;

const int N = 401;
int n, m, q;
int d[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		d[a][b] = -1;
		d[b][a] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j || d[i][j]) continue;
				if (d[i][k] == -1 && d[k][j] == -1) d[i][j] = -1;
				if (d[i][k] == 1 && d[k][j] == 1) d[i][j] = 1;
			}
		}
	}

	cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << d[a][b] << "\n";
	}
}