#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int x, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> x) {
		x *= 1e7;
		cin >> n;
		vector<int> legos(n);
		for (int i = 0; i < n; ++i) cin >> legos[i];
		sort(legos.begin(), legos.end());

		int l = 0, r = n - 1;
		bool flag = false;
		while (l < r) {
			int sum = legos[l] + legos[r];
			if (sum > x) r--;
			else if (sum < x) l++;
			else {
				cout << "yes " << legos[l] << " " << legos[r] << "\n";
				flag = true;
				break;
			}
		}

		if (!flag) cout << "danger\n";
	}
}