#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 200001;
const int MOD = 1000000007;
int lst[N];
int color[N];
vector<int> edges[N];
int n, m, c;
int it[N];
int ot[N];
int t;
ll ans;
vector<int> tree[N * 4];

void dfs(int node, int par) {
	it[node] = ++t;
	color[it[node]] = lst[node];
	for (int i : edges[node]) {
		if (par == i) continue;
		dfs(i, node);
	}
	ot[node] = t;
}

void build(int node, int s, int e) {
	if (s == e) tree[node] = { color[s] };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		vector<int>& left = tree[node * 2];
		vector<int>& right = tree[node * 2 + 1];
		vector<int> par(left.size() + right.size());
		merge(left.begin(), left.end(), right.begin(), right.end(), par.begin());
		tree[node] = par;
	}
}

int query(int node, int s, int e, int L, int R, int C) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return upper_bound(tree[node].begin(), tree[node].end(), C) - tree[node].begin();
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R, C);
	int right = query(node * 2 + 1, mid + 1, e, L, R, C);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> c;
	for (int i = 1; i <= n; ++i) cin >> lst[i];
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1, 1);
	build(1, 1, n);

	while (m--) {
		int V, C; cin >> V >> C;
		ans += query(1, 1, n, it[V], ot[V], C);
		if (ans >= MOD) ans %= MOD;
	}
	cout << ans;
}