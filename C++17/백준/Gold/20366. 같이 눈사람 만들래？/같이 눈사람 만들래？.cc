#include<iostream>
#include<algorithm>
using namespace std;

const int N = 600;
int arr[N];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	int mn = 2e9;
	for (int i = 0; i < n - 3; ++i) {
		if (mn == 0) break;

		for (int j = i + 3; j < n; ++j) {
			if (mn == 0) break;
			int sm1 = arr[i] + arr[j];
			int l = i + 1, r = j - 1;

			while (l < r) {
				int sm2 = arr[l] + arr[r];
				mn = min(mn, abs(sm1 - sm2));

				if (sm1 < sm2) --r;
				else if (sm1 > sm2) ++l;
				else break;
			}
		}
	}
	cout << mn;
}