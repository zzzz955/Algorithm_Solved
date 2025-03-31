#include<iostream>
#define ll long long
using namespace std;

const int N = 2e5 + 1;
int n, q;
int lst[N];
struct MS {
	ll M, S;
};
MS tree[N * 4];
ll lazy[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = { lst[s], lst[s] };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node].S = tree[node * 2].S + tree[node * 2 + 1].S;
		tree[node].M = min(tree[node * 2].M, tree[node * 2 + 1].M);
	}
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node].S += (e - s + 1) * lazy[node];
		tree[node].M += lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, ll val) {
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
	tree[node].S = tree[node * 2].S + tree[node * 2 + 1].S;
	tree[node].M = min(tree[node * 2].M, tree[node * 2 + 1].M);
}

ll minQuery(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return 2e9;
	if (L <= s && e <= R) return tree[node].M;
	int mid = (s + e) / 2;
	ll left = minQuery(node * 2, s, mid, L, R);
	ll right = minQuery(node * 2 + 1, mid + 1, e, L, R);
	return min(left, right);
}

ll sumQuery(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node].S;
	int mid = (s + e) / 2;
	ll left = sumQuery(node * 2, s, mid, L, R);
	ll right = sumQuery(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> lst[i];
	build(1, 1, n);

	while (q--) {
		char op; int l, r;
		cin >> op >> l >> r;
		if (op == 'M') cout << minQuery(1, 1, n, l, r) << "\n";
		else if (op == 'S') cout << sumQuery(1, 1, n, l, r) << "\n";
		else {
			ll v; cin >> v;
			update(1, 1, n, l, r, v);
		}
	}
}