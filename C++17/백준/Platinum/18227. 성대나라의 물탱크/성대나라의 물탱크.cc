#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const int N = 2e5 + 1;
int n, c, q;
ll tree[N * 4];
int it[N];
int ot[N];
int dep[N];
int t;
vector<int> edges[N];

void dfs(int level, int node, int par) {
	it[node] = ++t;
	dep[node] = level;
	for (int child : edges[node]) {
		if (child != par) dfs(level + 1, child, node);
	}
	ot[node] = t;
}

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node]++;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

ll query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, L, R);
	ll right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1, c, -1);
	//for (int i = 1; i <= n; ++i) cout << i << " : " << it[i] << " " << ot[i] << "\n";
	cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		if (a == 1) update(1, 1, n, it[b]);
		else cout << query(1, 1, n, it[b], ot[b]) * dep[b] << "\n";
	}
}