#include<iostream>
using namespace std;

const int N = 2e5 + 1;
int n, m;
int lst[N];
long long tree[N * 4];
int m_tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) {
		tree[node] = lst[s];
		m_tree[node] = lst[s];
	}
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		m_tree[node] = min(m_tree[node * 2], m_tree[node * 2 + 1]);
	}
}

void update(int node, int s, int e, int idx, int val) {
	if (s == e) {
		tree[node] = val;
		m_tree[node] = val;
	}
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		m_tree[node] = min(m_tree[node * 2], m_tree[node * 2 + 1]);
	}
}

long long sum_query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return sum_query(node * 2, s, mid, L, R) + sum_query(node * 2 + 1, mid + 1, e, L, R);
}

int min_query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 2e9;
	if (L <= s && e <= R) return m_tree[node];
	int mid = (s + e) / 2;
	return min(min_query(node * 2, s, mid, L, R), min_query(node * 2 + 1, mid + 1, e, L, R));
}

int getL(int i, int val) {
	int L = 1, R = i;
	int idx = i;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (min_query(1, 1, n, mid, i) >= val) {
			idx = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}
	return idx;
}

int getR(int i, int val) {
	int L = i, R = n;
	int idx = i;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (min_query(1, 1, n, i, mid) >= val) {
			idx = mid;
			L = mid + 1;
		}
		else R = mid - 1;
	}
	return idx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> lst[i];
	build(1, 1, n);

	cin >> m;
	while (m--) {
		int op, i, j; cin >> op >> i >> j;
		if (op == 1) update(1, 1, n, i, j);
		else {
			int L = getL(i, j);
			int R = getR(i, j);

			//cout << "L, R " << L << " " << R << "\n";
			cout << sum_query(1, 1, n, L, R) << "\n";
		}
	}
}