#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t;
vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	arr.reserve(40000);
	while (t--) {
		int n; cin >> n;
		arr.clear();

		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			auto it = lower_bound(arr.begin(), arr.end(), x);

			if (it == arr.end()) arr.push_back(x);
			else *it = x;
		}
		cout << arr.size() << "\n";
	}
	
}