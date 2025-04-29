#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 1;
int t, n;
int lst1[N], lst2[N];
int tree[N * 4];

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node]++;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> lst1[i];
		for (int i = 1; i <= n; ++i) {
			int idx; cin >> idx;
			lst2[idx] = i;
		}

		memset(tree, 0, sizeof(tree));
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			update(1, 1, n, lst2[lst1[i]]);
			ans += query(1, 1, n, lst2[lst1[i]] + 1, n);
		}
		cout << ans << "\n";
	}
}