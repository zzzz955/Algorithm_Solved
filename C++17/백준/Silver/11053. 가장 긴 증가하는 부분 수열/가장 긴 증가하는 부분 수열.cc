#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> lst;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		auto it = lower_bound(lst.begin(), lst.end(), a);
		if (it == lst.end()) lst.push_back(a);
		else *it = a;
	}
	cout << lst.size();
}