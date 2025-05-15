#include<iostream>
using namespace std;

const int N = 1e5 + 1;
int idx[N];
int tree[N * 4];

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
	cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		idx[a] = i;
	}

	int L = 1, R = n, t = 1;
	while (L <= R) {
		if (t++ % 2) {
			int sum = query(1, 1, n, 1, idx[L]);
			update(1, 1, n, idx[L]);
			cout << idx[L] - 1 - sum << "\n";
			L++;
		}
		else {
			int sum = query(1, 1, n, idx[R], n);
			update(1, 1, n, idx[R]);
			cout << n - idx[R] - sum << "\n";
			R--;
		}
	}
}