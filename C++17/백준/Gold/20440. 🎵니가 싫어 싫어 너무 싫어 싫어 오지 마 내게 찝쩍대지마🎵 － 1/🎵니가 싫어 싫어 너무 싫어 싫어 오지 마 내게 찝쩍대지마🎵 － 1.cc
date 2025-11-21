#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;

const int N = 1e6;
pii mos[N];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> times;
	for (int i = 0; i < n; ++i) {
		int st, et; cin >> st >> et;
		mos[i] = { st, et };
		times.push_back(st);
		times.push_back(et);
	}

	sort(times.begin(), times.end());
	times.erase(unique(times.begin(), times.end()), times.end());
	int m = times.size();
	
	vector<int> diff(m + 1, 0);
	for (int i = 0; i < n; ++i) {
		int st = mos[i].first;
		int et = mos[i].second;

		int si = lower_bound(times.begin(), times.end(), st) - times.begin();
		int ei = lower_bound(times.begin(), times.end(), et) - times.begin();

		++diff[si];
		--diff[ei];
	}

	int mx = 0;
	int cur = 0;
	for (int i = 0; i < m; ++i) {
		cur += diff[i];
		if (cur > mx) mx = cur;
	}

	long long si = 0, ei = 0;
	cur = 0;
	bool flag = false;
	for (int i = 0; i < m; ++i) {
		cur += diff[i];

		if (cur == mx) {
			if (!flag) {
				flag = true;
				si = times[i];
			}
			ei = times[i + 1];
		}
		else if (flag) break;
	}

	cout << mx << "\n" << si << " " << ei;
}