#include<iostream>
using namespace std;
const int N = 1e5;
int n;
int tree[N * 4];
int lazy[N * 4];

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int val) {
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
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx) {
	propagate(node, s, e);
	if (s == e) return tree[node];
	int mid = (s + e) / 2;
	if (idx <= mid) return query(node * 2, s, mid, idx);
	return query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		int L, R; cin >> L >> R;
		int left = query(1, 1, N, L);
		int right = query(1, 1, N, R);
		cout << left + right << "\n";
		update(1, 1, N, L, L, -left);
		update(1, 1, N, R, R, -right);
		update(1, 1, N, L + 1, R - 1, 1);
	}
}