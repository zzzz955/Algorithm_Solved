#include<iostream>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 1;
int n;
int lst[N];
int tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = lst[s];
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node] = 0;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int val) {
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (tree[node * 2] >= val) return query(node * 2, s, mid, val);
	else return query(node * 2 + 1, mid + 1, e, val - tree[node * 2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> lst[i];
	build(1, 1, n);

	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		int idx = query(1, 1, n, a);
		cout << idx << " ";
		update(1, 1, n, idx);
	}
}