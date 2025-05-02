#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6;
int n;
int lst[N];
pair<int, int> tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = { lst[s], s };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

pair<int, int> getIndex(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return {15001, -1};
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	pair<int, int> left = getIndex(node * 2, s, mid, L, R);
	pair<int, int> right = getIndex(node * 2 + 1, mid + 1, e, L, R);
	return min(left, right);
}

int query(int L, int R) {
	if (L > R) return 0;
	pair<int, int> res = getIndex(1, 0, n - 1, L, R);
	int all = res.first * (R - L + 1);
	int left = query(L, res.second - 1);
	int right = query(res.second + 1, R);
	return max({ all, left, right });
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	build(1, 0, n - 1);
	cout << query(0, n - 1);
}