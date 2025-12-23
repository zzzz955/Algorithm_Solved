#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 1;
int v[N];
vector<int> tree[N * 4];
int it[N];
int ot[N];
int arr[N];
int t;
int n;
vector<int> edges[N];

void dfs(int cn) {
	it[cn] = ++t;
	arr[t] = v[cn];
	for (int nn : edges[cn]) dfs(nn);
	ot[cn] = t;
}

void build(int node, int s, int e) {
	if (s == e) tree[node] = { arr[s] };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		vector<int>& left = tree[node * 2];
		vector<int>& right = tree[node * 2 + 1];
		vector<int> par(left.size() + right.size());
		merge(left.begin(), left.end(), right.begin(), right.end(), par.begin());
		tree[node] = move(par);
	}
}

int query(int node, int s, int e, int L, int R, int x) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), x);
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, L, R, x) + query(node * 2 + 1, mid + 1, e, L, R, x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> v[i];
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		edges[p].push_back(i);
	}
	dfs(1);
	build(1, 1, n);

	for (int i = 1; i <= n; ++i) {
		cout << query(1, 1, n, it[i], ot[i], v[i]) << "\n";
	}
}