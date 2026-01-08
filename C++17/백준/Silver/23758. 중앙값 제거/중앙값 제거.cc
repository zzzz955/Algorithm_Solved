#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e6;
int arr[N];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	int ans = 0;
	for (int i = (n - 1) / 2; i >= 0; --i) {
		if (arr[i] == 1) break;
		while (arr[i] > 1) {
			++ans;
			arr[i] >>= 1;
		}
	}

	cout << ++ans;
}