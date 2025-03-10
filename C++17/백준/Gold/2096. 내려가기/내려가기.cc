#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5;
int n;
int lst[N][3], dp[3][2], pre[3][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> lst[i][j];

	for (int i = 0; i < 3; ++i) {
		dp[i][0] = dp[i][1] = lst[0][i];
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			pre[j][0] = dp[j][0];
			pre[j][1] = dp[j][1];
		}

		for (int j = 0; j < 3; ++j) {
			if (j == 0) {
				dp[j][0] = lst[i][j] + max(pre[j][0], pre[j + 1][0]);
				dp[j][1] = lst[i][j] + min(pre[j][1], pre[j + 1][1]);
			}
			else if (j == 1) {
				dp[j][0] = lst[i][j] + max({ pre[j - 1][0], pre[j][0], pre[j + 1][0] });
				dp[j][1] = lst[i][j] + min({ pre[j - 1][1], pre[j][1], pre[j + 1][1] });
			}
			else {
				dp[j][0] = lst[i][j] + max(pre[j - 1][0], pre[j][0]);
				dp[j][1] = lst[i][j] + min(pre[j - 1][1], pre[j][1]);
			}
		}
	}
	cout << max({ dp[0][0], dp[1][0], dp[2][0] }) << " "
		<< min({ dp[0][1], dp[1][1], dp[2][1] });
}