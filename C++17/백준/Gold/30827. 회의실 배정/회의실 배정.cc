#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

const int N = 200000;
int n, k, ans;
struct P {
	int st, et;
	bool operator<(const P& other) const {
		if (et == other.et) return st < other.st;
		return et < other.et;
	}
};
P lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		lst[i] = { a, b };
	}

	sort(lst, lst + n);
	multiset<int> ms;
	for (int i = 0; i < k; ++i) ms.insert(0);
	for (int i = 0; i < n; ++i) {
		auto it = ms.lower_bound(lst[i].st);
		if (it != ms.begin() && *--it < lst[i].st) {
			ms.erase(it);
			ms.insert(lst[i].et);
			ans++;
		}
	}
	cout << ans;
}