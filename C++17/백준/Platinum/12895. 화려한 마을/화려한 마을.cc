#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100001;
int n, t, q;
int tree[N * 4];
int lazy[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = 1 << 1;
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] | tree[node * 2 + 1];
	}
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] = lazy[node];
		if (s != e) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] = val;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, val);
	update(node * 2 + 1, mid + 1, e, L, R, val);
	tree[node] = tree[node * 2] | tree[node * 2 + 1];
}

int query(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, e, L, R);
	return left | right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t >> q;
	build(1, 1, n);
	while (q--) {
		char op;
		int l, r;
		cin >> op >> l >> r;
		if (l > r) swap(l, r);
		if (op == 'C') {
			int v; cin >> v;
			update(1, 1, n, l, r, 1 << v);
		}
		else {
			int res = query(1, 1, n, l, r);
			int cnt = 0;
			for (int i = 0; i < 32; ++i) {
				if (res & (1 << i)) cnt++;
			}
			cout << cnt << "\n";
		}
	}
}