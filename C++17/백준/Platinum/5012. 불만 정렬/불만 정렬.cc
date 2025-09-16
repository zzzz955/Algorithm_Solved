#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;

const int N = 1e5 + 1;
int n;
int lst[N];
ll tree[N * 4];
ll h[N];

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
	return query(node * 2, s, mid, L, R) + query(node * 2 + 1, mid + 1, e, L, R);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> lst[i];

	for (int i = 1; i <= n; ++i) {
		h[i] = query(1, 1, n, lst[i] + 1, n);
		update(1, 1, n, lst[i]);
	}

	memset(tree, 0, sizeof(tree));
	ll ans = 0;
	for (int i = n; i >= 1; --i) {
		ans += h[i] * query(1, 1, n, 1, lst[i] - 1);
		update(1, 1, n, lst[i]);
	}
	cout << ans;
}