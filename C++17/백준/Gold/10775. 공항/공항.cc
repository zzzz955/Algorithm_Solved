#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int G = 100001;
int g, p, ans;
set<int> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> g >> p;
	for (int i = 1; i <= g; ++i) dic.insert(i);
	while (p--) {
		int gate; cin >> gate;
		auto it = dic.upper_bound(gate);
		if (it == dic.begin()) {
			cout << ans;
			return 0;
		}
		else {
			dic.erase(--it);
			ans++;
		}
	}
	cout << ans;
}