#include<iostream>
using namespace std;
using ll = long long;

const int N = 1e6 + 1;
int q, t, k;
struct Node {
	int sum, mn;
};
Node tree[N * 4];

void update(int node, int s, int e, int idx, int val) {
	if (s == e) tree[node].sum += val, tree[node].mn += val;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
		tree[node].mn = min(tree[node * 2].mn, tree[node * 2 + 1].mn);
	}
}

int get_idx(int node, int s, int e) {
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (tree[node * 2].mn == 0) return get_idx(node * 2, s, mid);
	else if (tree[node * 2 + 1].mn == 0) return get_idx(node * 2 + 1, mid + 1, e);
	return N;
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node].sum;
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, L, R) + query(node * 2 + 1, mid + 1, e, L, R);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> q;
	while (q--) {
		cin >> t >> k;
		if (t == 1) update(1, 1, N, k, 1);
		else update(1, 1, N, k, -1);

		int idx = get_idx(1, 1, N);
		cout << query(1, 1, N, 1, idx) << "\n";
	}
}