#include<iostream>
using namespace std;

const int N = 1e5 + 1;
int v[N];
int tree[N * 4];

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

	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		int c; cin >> c;
		if (!v[c]) {
			v[c] = i;
			update(1, 1, n * 2, i, 1);
		}
		else {
			update(1, 1, n * 2, v[c], -1);
			ans += query(1, 1, n * 2, v[c], i);
		}
	}
	cout << ans;
}