#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5 + 1;
int lst[N];
vector<int> tree[N * 4];
int n, m;

void build(int node, int s, int e) {
	if (s == e) tree[node] = { lst[s] };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		vector<int>& L = tree[node * 2];
		vector<int>& R = tree[node * 2 + 1];
		tree[node].resize(L.size() + R.size());
		merge(L.begin(), L.end(), R.begin(), R.end(), tree[node].begin());
	}
}

int query(int node, int s, int e, int L, int R, int val) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R, val);
	int right = query(node * 2 + 1, mid + 1, e, L, R, val);
	return left + right;
}

int bs(int s, int e, int k) {
	int L = -1e9, R = 1e9;
	while (L <= R) {
		int mid = (L + R) / 2;
		int cnt = query(1, 1, n, s, e, mid);
		if (cnt >= k) R = mid - 1;
		else L = mid + 1;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> lst[i];

	build(1, 1, n);
	while (m--) {
		int i, j, k; cin >> i >> j >> k;
		cout << bs(i, j, k) << "\n";
	}
}