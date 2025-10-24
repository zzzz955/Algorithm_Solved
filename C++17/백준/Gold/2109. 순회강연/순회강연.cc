#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

struct Pre {
	int p, d;
	bool operator<(const Pre& other) const {
		return p > other.p;
	}
};
const int N = 1e4;
int n;
Pre lst[N];
set<int> day;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p, d; cin >> p >> d;
		lst[i] = { p, d };
	}
	for (int i = 1; i <= 10000; ++i) day.insert(i);
	sort(lst, lst + n);

	int pp = 0;
	for (int i = 0; i < n; ++i) {
		const Pre& pre = lst[i];
		int p = pre.p, d = pre.d;
		//cout << p << " " << d << "\n";

		auto it = day.upper_bound(d);
		if (it == day.begin()) continue;
		day.erase(--it);
		pp += p;
	}
	cout << pp;
}