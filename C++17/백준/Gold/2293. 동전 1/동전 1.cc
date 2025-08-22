#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int K = 1e4 + 1;
int n, k;
int dp[K];

int main() {
	cin >> n >> k;
	vector<int> lst;
	while (n--) {
		int a; cin >> a;
		if (a > k) continue;
		lst.push_back(a);
	}

	dp[0] = 1;
	for (int j : lst) {
		for (int i = j; i <= k; ++i) {
			dp[i] += dp[i - j];
		}
	}
	cout << dp[k];
}