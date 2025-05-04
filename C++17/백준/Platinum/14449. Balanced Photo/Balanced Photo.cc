#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cstring>
using namespace std;

const int N = 1e5;
int n;
int lst[N];
int sorted[N];
unordered_map<int, int> comp;
int comped[N];
int tree[N * 4];
int H[N];
int L[N];
int R[N];

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node]++;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
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

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		sorted[i] = lst[i];
	}

	sort(sorted, sorted + n);
	for (int i = 0; i < n; ++i) comp[sorted[i]] = i;

	for (int i = 0; i < n; ++i) H[i] = comp[lst[i]];

	for (int i = 0; i < n; ++i) {
		L[i] = query(1, 0, n - 1, H[i] + 1, n - 1);
		update(1, 0, n - 1, H[i]);
	}

	memset(tree, 0, sizeof(tree));
	for (int i = n - 1; i >= 0; --i) {
		R[i] = query(1, 0, n - 1, H[i] + 1, n - 1);
		update(1, 0, n - 1, H[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (min(L[i], R[i]) * 2 < max(L[i], R[i])) ans++;
	}
	cout << ans;
}