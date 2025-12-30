#include<iostream>
#include<array>
using namespace std;

const int N = 250001;
struct Node {
	int sum;
	int lazy;
	array<int, 10> cnt{};
};
Node tree[N * 4];
int n, m;
string str;

void update_parent(int node) {
	int temp_sum = 0;
	for (int i = 0; i < 10; ++i) {
		tree[node].cnt[i] = tree[node * 2].cnt[i] + tree[node * 2 + 1].cnt[i];
		temp_sum += tree[node].cnt[i] * i;
	}
	tree[node].sum = temp_sum;
}

void build(int node, int s, int e) {
	if (s == e) {
		int d = str[s - 1] - '0';
		tree[node].sum = d;
		tree[node].lazy = 0;
		++tree[node].cnt[d];
		return;
	}
	int mid = (s + e) / 2;
	build(node * 2, s, mid);
	build(node * 2 + 1, mid + 1, e);
	update_parent(node);
}

void update_range(int node, int x) {
	array<int, 10> temp_array{};
	for (int i = 0; i < 10; ++i) temp_array[(i + x) % 10] = tree[node].cnt[i];
	tree[node].cnt = temp_array;

	int temp_sum = 0;
	for (int i = 0; i < 10; ++i) temp_sum += i * temp_array[i];
	tree[node].sum = temp_sum;
}

void propagate(int node, int s, int e) {
	if (tree[node].lazy) {
		update_range(node, tree[node].lazy);

		if (s != e) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}

		tree[node].lazy = 0;
	}
}

void update(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		++tree[node].lazy;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R);
	update(node * 2 + 1, mid + 1, e, L, R);
	update_parent(node);
}

int query(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node].sum;
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, L, R) + query(node * 2 + 1, mid + 1, e, L, R);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> str;
	build(1, 1, n);
	while (m--) {
		int L, R; cin >> L >> R;
		cout << query(1, 1, n, L, R) << "\n";
		update(1, 1, n, L, R);
	}
}