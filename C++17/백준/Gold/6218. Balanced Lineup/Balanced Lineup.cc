#include<iostream>
using namespace std;
using pii = pair<int, int>;

const int MAX = 1e6;
const int N = 5e4 + 1;
int n, q;
int lst[N];
pii tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = { lst[s], lst[s] };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = { max(tree[node * 2].first, tree[node * 2 + 1].first), min(tree[node * 2].second, tree[node * 2 + 1].second) };
	}
}

pii query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return { 0, MAX };
	else if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	pii left = query(node * 2, s, mid, L, R);
	pii right = query(node * 2 + 1, mid + 1, e, L, R);
	return { max(left.first, right.first), min(left.second, right.second) };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> lst[i];
	build(1, 1, n);

	while (q--) {
		int l, r; cin >> l >> r;
		pii res = query(1, 1, n, l, r);
		cout << res.first - res.second << "\n";
	}
}