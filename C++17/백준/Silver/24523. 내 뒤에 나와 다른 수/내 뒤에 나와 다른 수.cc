#include<iostream>
#include<vector>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; ++i) cin >> arr[i];

	vector<int> ans(n + 1, -1);
	int l = 1;
	while (l < n) {
		int r = l + 1;

		while (r <= n && arr[l] == arr[r]) ++r;
		if (r > n) break;
		while (l < r) ans[l++] = r;
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}