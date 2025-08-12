#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5000;
const int C = 1e8;
int n, c;
int lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		if (lst[i] == c) {
			cout << 1;
			return 0;
		}
	}

	sort(lst, lst + n);
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (lst[i] + lst[j] == c) {
				cout << 1;
				return 0;
			}
			auto uit = upper_bound(lst + j + 1, lst + n, c - lst[i] - lst[j]);
			auto lit = lower_bound(lst + j + 1, lst + n, c - lst[i] - lst[j]);
			if (uit - lit) {
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;
	return 0;
 }