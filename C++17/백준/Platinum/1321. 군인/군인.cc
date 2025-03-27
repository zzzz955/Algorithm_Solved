#include<iostream>
using namespace std;

const int N = 500001;
int n, m;
int lst[N];
int tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = lst[s];
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(int node, int s, int e, int idx, int val) {
	if (s == e) tree[node] += val;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int idx) {
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (idx <= tree[node * 2]) return query(node * 2, s, mid, idx);
	return query(node * 2 + 1, mid + 1, e, idx - tree[node * 2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> lst[i];
	build(1, 1, n);

	cin >> m;
	while (m--) {
		int op, idx; cin >> op >> idx;
		if (op == 1) {
			int val; cin >> val;
			update(1, 1, n, idx, val);
		}
		else {
			cout << query(1, 1, n, idx) << "\n";
		}
	}
}