#include<iostream>
using namespace std;

const int N = 1e4 + 1;
int n, k, m;
int tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = 1;
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int k) {
	if (s == e) {
		tree[node] = 0;
		return s;
	}
	int mid = (s + e) / 2;

	int result = k <= tree[node * 2] ? query(node * 2, s, mid, k) : query(node * 2 + 1, mid + 1, e, k - tree[node * 2]);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n >> k >> m;
		if (!n && !k && !m) break;
		build(1, 1, n);

		int idx = m, res = -1;
		for (int i = 1; i <= n; ++i) {
			res = query(1, 1, n, idx);

			if (i < n) {
				idx = (idx - 1 + k) % tree[1];
				if (idx == 0) idx = tree[1];
			}
		}
		cout << res << "\n";
	}
}