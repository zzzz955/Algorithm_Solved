#include<iostream>
using namespace std;

const int N = 5001;
int n, r, c, w;
bool F[N][N];
int PS[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> c >> w;
	while (n--) {
		int a, b; cin >> a >> b;
		F[a][b] = true;
	}

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			PS[i][j] = PS[i - 1][j] + PS[i][j - 1] - PS[i - 1][j - 1] + F[i][j];
			//cout << PS[i][j] << " ";
		}
		//cout << "\n";
	}

	int ans = 0;
	int x = 0, y = 0;
	const int h = w / 2;

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (F[i][j]) continue;

			int top = max(1, i - h);
			int bottom = min(r, i + h);
			int left = max(1, j - h);
			int right = min(c, j + h);

			int pre_sum = PS[bottom][right] - PS[top - 1][right] - PS[bottom][left - 1] + PS[top - 1][left - 1];

			if (ans < pre_sum) {
				ans = pre_sum;
				x = i;
				y = j;
			}
		}
	}
	cout << ans << "\n";
	cout << x << " " << y;
}