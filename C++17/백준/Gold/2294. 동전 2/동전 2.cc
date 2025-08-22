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

	lst.erase(unique(lst.begin(), lst.end()), lst.end());
	sort(lst.begin(), lst.end());
	
	for (int i = 1; i <= k; ++i) dp[i] = 2e9;
	dp[0] = 0;
	for (int j : lst) {
		for (int i = j; i <= k; ++i) {
			dp[i] = min(dp[i], dp[i - j] + 1);
		}
	}
	cout << (dp[k] == 2e9 ? -1 : dp[k]);
}