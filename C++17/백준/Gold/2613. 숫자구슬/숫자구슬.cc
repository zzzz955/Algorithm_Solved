#include<iostream>
#include<vector>
using namespace std;

const int N = 300;
int n, m;
int arr[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		r += arr[i];
		l = max(l, arr[i]);
	}
	
	int mn = r;
	vector<int> path;
	while (l <= r) {
		int mid = (l + r) / 2;

		vector<int> g;
		int sum = 0, cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (sum + arr[i] > mid) {
				g.push_back(cnt);
				cnt = 1;
				sum = arr[i];
			}
			else {
				sum += arr[i];
				++cnt;
			}
		}
		g.push_back(cnt);

		if (g.size() > m) l = mid + 1;
		else {
			int idx = g.size() - 1;
			while (g.size() < m && idx >= 0) {
				if (g[idx] == 1) {
					--idx;
					continue;
				}
				--g[idx];
				g.push_back(1);
			}
			r = mid - 1;
			path = g;
			mn = mid;
		}
	}

	cout << mn << "\n";
	for (int i : path) cout << i << " ";
}