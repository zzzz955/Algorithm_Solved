#include<iostream>
#include<set>
using namespace std;

int n, q;
set<int> d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		int v; cin >> v;
		if (v) d.insert(i);
	}

	int x = 1;
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
			int i; cin >> i;
			if (d.count(i)) d.erase(i);
			else d.insert(i);
		}
		else if (c == 2) {
			int p; cin >> p;
			p %= n;
			x = (x + p) % n ? (x + p) % n : n;
		}
		else {
			if (d.empty()) cout << -1 << "\n";
			else {
				auto back = d.lower_bound(x);
				if (back != d.end()) cout << *back - x << "\n";
				else {
					auto front = d.lower_bound(0);
					cout << n - x + *front << "\n";
				}
			}
		}
		//cout << "x : " << x << "\n";
	}
}