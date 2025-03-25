#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int n;
pair<int, int> lst[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int st, et; cin >> st >> et;
		lst[i] = { et, st };
	}
	sort(lst, lst + n);

	multiset<int> dic;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		auto it = dic.upper_bound(lst[i].second);
		if (it == dic.begin()) dic.insert(lst[i].first);
		else {
			dic.erase(--it);
			dic.insert(lst[i].first);
		}
		ans = max(ans, (int)dic.size());
	}
	cout << ans;
}