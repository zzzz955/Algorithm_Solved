#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5;
int n, d;
struct PV {
	int p, v;
	bool operator<(const PV& other) const {
		return p < other.p;
	}
};
PV pvs[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		int p, v; cin >> p >> v;
		pvs[i] = { p, v };
	}
	sort(pvs, pvs + n);

	int l = 0, r = 0;
	long long cv = pvs[0].v;
	long long mx = cv;
	while (++r < n) {
		cv += pvs[r].v;

		while (pvs[l].p + d <= pvs[r].p) {
			cv -= pvs[l].v;
			++l;
		}

		if (mx < cv) mx = cv;
	}
	cout << mx;
}