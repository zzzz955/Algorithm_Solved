#include<iostream>
using namespace std;

const int N = 1e5;
int lst[N];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	int l = 0, r = n - 1, ans = 1e9;
	while (l < r) {
		int sum = lst[l] + lst[r];
		if (abs(ans) > abs(sum)) ans = sum;
		if (sum > 0) r--;
		else if (sum < 0) l++;
		else break;
	}
	cout << ans;
}