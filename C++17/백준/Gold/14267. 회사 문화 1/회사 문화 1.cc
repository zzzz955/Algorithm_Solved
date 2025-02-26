#include<iostream>
#include<vector>
using namespace std;

const int N = 100001;
int n, m;
vector<int> lst[N];
int it[N];
int ot[N];
int t;
int tree[N * 4];
int lazy[N * 4];

void dfs(int cur) {
	it[cur] = ++t;
	for (int next : lst[cur]) dfs(next);
	ot[cur] = t;
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int V) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] += V;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, V);
	update(node * 2 + 1, mid + 1, e, L, R, V);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx) {
	propagate(node, s, e);
	if (s == e) return tree[node];
	int mid = (s + e) / 2;
	if (idx <= mid) return query(node * 2, s, mid, idx);
	return query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int trash; cin >> trash;
	for (int i = 2; i <= n; ++i) {
		int par; cin >> par;
		lst[par].push_back(i);
	}

	dfs(1);
	while (m--) {
		int a, b; cin >> a >> b;
		update(1, 1, n, it[a], ot[a], b);
	}

	for (int i = 1; i <= n; ++i) {
		cout << query(1, 1, n, it[i]) << " ";
	}
}