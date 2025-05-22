#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 1;
int n, m;
vector<int> edges[N];
int it[N];
int ot[N];
int ti[N];
int t;
int tree[N * 4];
int lazy[N * 4];
int lst[N];

void dfs(int cur, int par) {
	it[cur] = ++t;
	ti[t] = lst[cur];
	for (int next : edges[cur]) {
		if (next != par) dfs(next, cur);
	}
	ot[cur] = t;
}

void build(int node, int s, int e) {
	if (s == e) tree[node] = ti[s];
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
	}
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		if ((e - s + 1) % 2) tree[node] ^= lazy[node];
		if (s != e) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] ^= val;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, val);
	update(node * 2 + 1, mid + 1, e, L, R, val);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	propagate(node, s, e);
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, L, R) ^ query(node * 2 + 1, mid + 1, e, L, R);
}

//int query(int node, int s, int e, int idx) {
//	propagate(node, s, e);
//	if (s == e) return tree[node];
//	int mid = (s + e) / 2;
//	if (idx <= mid) return query(node * 2, s, mid, idx);
//	return query(node * 2 + 1, mid + 1, e, idx);
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) cin >> lst[i];

	dfs(1, -1);
	build(1, 1, n);
	while (m--) {
		int op; cin >> op;
		if (op == 1) {
			int idx; cin >> idx;
			cout << query(1, 1, n, it[idx], ot[idx]) << "\n";
			//cout << query(1, 1, n, it[idx]) << "\n";
		}
		else {
			int L, R; cin >> L >> R;
			update(1, 1, n, it[L], ot[L], R);
		}
	}
}