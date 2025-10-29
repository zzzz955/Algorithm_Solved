#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 50;
vector<int> edges[N];

int dfs(int cn) {
	if (edges[cn].empty()) return 0;

	vector<int> times;
	for (int nn : edges[cn]) {
		times.push_back(dfs(nn));
	}
	
	sort(times.begin(), times.end(), greater<int>());
	int mx = 0;
	for (int i = 0; i < times.size(); ++i) {
		mx = max(mx, times[i] + i + 1);
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, temp; cin >> n >> temp;
	for (int i = 1; i < n; ++i) {
		int p; cin >> p;
		edges[p].push_back(i);
	}

	cout << dfs(0);
}