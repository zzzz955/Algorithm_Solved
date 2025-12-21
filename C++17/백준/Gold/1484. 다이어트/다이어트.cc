#include<iostream>
#include<set>
#include<cmath>
using namespace std;
using ll = long long;

set<ll> d;
int g;
ll idx;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	cin >> g;
	d.insert(++idx);
	while (++idx) {
		ll b = *d.rbegin();
		ll c = idx * idx;
		if (c - b > g) break;
		d.insert(c);
	}

	bool f = false;
	for (ll i: d) {
		ll t = i - g;
		
		if (d.count(t)) {
			f = true;
			cout << (int)sqrt(i) << "\n";
		}
	}
	if (!f) cout << -1;
}