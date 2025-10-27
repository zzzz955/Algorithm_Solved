#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1001;
int n;
int lst[N];
int asc[N];
int desc[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		asc[i] = 1;
		desc[i] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (lst[j] < lst[i]) {
				asc[i] = max(asc[i], asc[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= i; --j) {
			if (lst[j] < lst[i]) {
				desc[i] = max(desc[i], desc[j] + 1);
			}
		}
	}

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		//cout << asc[i] << " " << desc[i] << " " << asc[i] + desc[i] - 1 << "\n";
		mx = max(mx, asc[i] + desc[i] - 1);
	}
	cout << mx;
}