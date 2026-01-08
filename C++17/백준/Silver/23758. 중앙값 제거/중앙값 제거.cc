#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e6;
int arr[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (register int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	int ans = 0;
	for (register int i = (n - 1) / 2; i >= 0; --i) {
		int x = arr[i];
		if (x == 1) break;
		ans += 31 - __builtin_clz((unsigned)x);
	}

	cout << ++ans;
}