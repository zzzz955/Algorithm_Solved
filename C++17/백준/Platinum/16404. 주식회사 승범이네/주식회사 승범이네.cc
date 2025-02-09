#include<iostream>
#include<vector>
using namespace std;

const int N = 100001;
int n, m;
int it[N];
int ot[N];
int t;
int tree[N * 4];
int lazy[N * 4];
vector<int> child[N];

void dfs(int cur) {
	it[cur] = ++t;
	for (int next : child[cur]) {
		dfs(next);
	}
	ot[cur] = t;
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] += val;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, val);
	update(node * 2 + 1, mid + 1, e, L, R, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx) {
	propagate(node, s, e);
	if (s == e) return tree[node];
	int mid = (s + e) / 2;
	if (idx <= mid) return query(node * 2, s, mid, idx);
	else return query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int temp; cin >> temp;
	for (int i = 2; i <= n; ++i) {
		int node; cin >> node;
		child[node].push_back(i);
	}
	dfs(1);
	while (m--) {
		int op; cin >> op;
		if (op == 1) {
			int i, w; cin >> i >> w;
			update(1, 1, n, it[i], ot[i], w);
		}
		else {
			int i; cin >> i;
			cout << query(1, 1, n, it[i]) << "\n";;
		}
	}
}