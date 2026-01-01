#include<iostream>
using namespace std;

const int N = 1001;
int n, m, k;
int pj[N][N], po[N][N], pi[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			pj[i][j] = pj[i][j - 1] + pj[i - 1][j] - pj[i - 1][j - 1];
			po[i][j] = po[i][j - 1] + po[i - 1][j] - po[i - 1][j - 1];
			pi[i][j] = pi[i][j - 1] + pi[i - 1][j] - pi[i - 1][j - 1];

			char c; cin >> c;
			if (c == 'J') ++pj[i][j];
			else if (c == 'O') ++po[i][j];
			else ++pi[i][j];
		}
	}

	while (k--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << pj[x2][y2] - pj[x2][y1 - 1] - pj[x1 - 1][y2] + pj[x1 - 1][y1 - 1] << " "
			<< po[x2][y2] - po[x2][y1 - 1] - po[x1 - 1][y2] + po[x1 - 1][y1 - 1] << " "
			<< pi[x2][y2] - pi[x2][y1 - 1] - pi[x1 - 1][y2] + pi[x1 - 1][y1 - 1] << "\n";
	}
}