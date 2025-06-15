#include<iostream>
#include<vector>
#include<unordered_map>
#define ll long long
using namespace std;

void get_slices(vector<int>& pizza, unordered_map<int, int>& dic, int size, int k) {
	vector<int> prefix(2 * size + 1, 0);
	for (int i = 0; i < 2 * size; i++) {
		prefix[i + 1] = prefix[i] + pizza[i % size];
	}

	int total = prefix[size];
	if (total <= k) dic[total]++;

	for (int len = 1; len < size; len++) {
		for (int start = 0; start < size; start++) {
			int sum = prefix[start + len] - prefix[start];
			if (sum <= k) dic[sum]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n, m;
	cin >> k >> n >> m;
	vector<int> a(n), b(m);
	unordered_map<int, int> A, B;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	
	get_slices(a, A, n, k);
	get_slices(b, B, m, k);

	ll ans = 0;
	if (A[k]) ans += A[k];
	if (B[k]) ans += B[k];
	for (auto& d : A) {
		int need = k - d.first;
		if (need > 0 && B[need]) {
			ans += (ll)d.second * B[need];
		}
	}
	cout << ans;
}