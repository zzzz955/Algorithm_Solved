#include<iostream>
using namespace std;
using ll = long long;

const int N = 5e5 + 1;
int tree[N * 4];
int n, h;
ll l;

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, L, R) + query(node * 2 + 1, mid + 1, e, L, R);
}

void update(int node, int s, int e, int idx) {
	if (s == e) ++tree[node];
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;	
	ll a = 0;
	for (int i = 0; i < n; ++i) {
		cin >> h;
		a += query(1, 1, n, h + 1, n);
		update(1, 1, n, h);
	}
	cout << min(a + l, 1ll * n * (n - 1) / 2);
}