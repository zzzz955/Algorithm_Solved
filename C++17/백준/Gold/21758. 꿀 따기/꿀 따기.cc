#include<iostream>
using namespace std;

const int N = 1e5 + 1;
int a[N];
int ltor[N + 1];
int rtol[N + 1];
int n;

int case1() {
	int mx = 0;
	for (int i = 2; i <= n - 1; ++i) {
		int val = ltor[i] - ltor[1] + rtol[i] - rtol[n];
		if (mx < val) mx = val;
	}
	return mx;
}

int case2() {
	int mx = 0;
	for (int i = n - 1; i >= 2; --i) {
		int val = rtol[1] * 2 - rtol[i] - a[i] - a[n];
		if (mx < val) mx = val;
	}
	return mx;
}

int case3() {
	int mx = 0;
	for (int i = 2; i <= n - 1; ++i) {
		int val = ltor[n] * 2 - ltor[i] - a[i] - a[1];
		if (mx < val) mx = val;
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) ltor[i] = ltor[i - 1] + a[i];
	for (int i = n; i >= 1; --i) rtol[i] = rtol[i + 1] + a[i];
	//cout << ltor[1] << " " << ltor[n] << " " << rtol[1] << " " << rtol[n] << "\n";
	
	int ans = case1();
	ans = max(ans, case2());
	ans = max(ans, case3());
	cout << ans;
}