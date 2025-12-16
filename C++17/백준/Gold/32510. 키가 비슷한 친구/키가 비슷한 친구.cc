#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;

const int N = 5e5 + 1;
int t, n, k;
int tree[N * 4];

void update(int node, int s, int e, int idx, int val) {
	if (s == e) tree[node] = min(tree[node], val);
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 2e9;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return min(query(node * 2, s, mid, L, R), query(node * 2 + 1, mid + 1, e, L, R));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int c = 1; c <= t; ++c) {
		ll ans = 0;
		cin >> n >> k;
		fill(tree, tree + N * 4, 2e9);

		for (int i = 0; i < n; ++i) {
			int v; cin >> v;
			update(1, 0, 5e5, v, i);
			int res = query(1, 0, 5e5, v - k, v);
			ans += i - res;
		}

		cout << "Case #" << c << "\n" << ans << "\n";
	}
}