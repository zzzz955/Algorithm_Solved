#include<iostream>
using namespace std;

int n;
int dp[31];

int main() {
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= 30; i += 2) dp[i] = dp[i - 2] * 4 - dp[i - 4];
	cin >> n;
	cout << dp[n];
}