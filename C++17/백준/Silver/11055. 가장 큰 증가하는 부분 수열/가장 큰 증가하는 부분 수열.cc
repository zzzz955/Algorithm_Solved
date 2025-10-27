#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1001;
int n;
int lst[N];
int dp[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		dp[i] = lst[i];
	}

	for (int i = 0; i < n; ++i) {
		int mx = 0;
		for (int j = 0; j < i; ++j) {
			if (lst[j] < lst[i]) {
				mx = max(mx, dp[j]);
			}
		}
		dp[i] += mx;
	}
	cout << *max_element(dp, dp + n);
}