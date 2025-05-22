#include<iostream>
using namespace std;

const int N = 2e5 + 1;
int n, m;
int lst[N];
int tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = lst[s] == lst[s + 1] ? 0 : 1;
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node] = lst[s] == lst[s + 1] ? 0 : 1;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, L, R) + query(node * 2 + 1, mid + 1, e, L, R);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> lst[i];
	build(1, 1, n);

	while (m--) {
		int op, L, R; cin >> op >> L >> R;
		if (op == 1) {
			lst[L] = R;
			update(1, 1, n, L);
			update(1, 1, n, L - 1);
		}
		else {
			cout << query(1, 1, n, L, R - 1) + 1 << "\n";
		}
	}
}