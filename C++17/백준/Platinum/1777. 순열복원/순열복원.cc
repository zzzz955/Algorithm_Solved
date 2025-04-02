#include<iostream>
using namespace std;

const int N = 1e5 + 1;
int n, s;
int lst[N];
int ans[N];
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
	if (s == e) --tree[node];
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
	if (val < tree[node * 2 + 1]) return query(node * 2 + 1, mid + 1, e, val);
	return query(node * 2, s, mid, val - tree[node * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) lst[i] = 1;
	build(1, 1, n);

	for (int i = 1; i <= n; ++i) cin >> lst[i];
	for (int i = n; i >= 1; --i) {
		s = lst[i];
		int idx = query(1, 1, n, s);
		//cout << "result of query : " << idx << "\n";
		ans[idx] = i;
		update(1, 1, n, idx);
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}