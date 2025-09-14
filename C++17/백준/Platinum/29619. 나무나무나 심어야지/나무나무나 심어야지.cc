#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 1;
int n, m;
int lst[N];
int tree[N * 4];
struct Query {
	int op, i, j, w;
};
vector<Query> queries;
int t;
int it[N];
int ot[N];
int val[N];
int tval[N];
vector<int> edges[N];
vector<int> ans;

void dfs(int cn) {
	it[cn] = ++t;
	tval[t] = val[cn];
	for (int nn : edges[cn]) dfs(nn);
	ot[cn] = t;
}

void build(int node, int s, int e) {
	if (s == e) tree[node] = tval[s];
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

	int trash;
	cin >> n >> m >> trash;
	for (int i = 2; i <= n; ++i) {
		int par; cin >> par;
		edges[par].push_back(i);
	}

	for (int i = 1; i <= n; ++i) cin >> val[i];

	while (m--) {
		int op, i; cin >> op >> i;
		if (op == 1) {
			int j, w; cin >> j >> w;
			queries.push_back({ op, i, j, w });
			edges[i].push_back(j);
			val[j] = w;
			n++;
		}
		else queries.push_back({ op, i });
	}

	dfs(1);
	build(1, 1, n);

	while (!queries.empty()) {
		Query q = queries.back();
		queries.pop_back();

		if (q.op == 1) update(1, 1, n, it[q.j], -q.w);
		else {
			int res = query(1, 1, n, it[q.i], ot[q.i]);
			ans.push_back(!res ? -1 : res);
		}
	}

	while (!ans.empty()) {
		cout << ans.back() << "\n";
		ans.pop_back();
	}
}