#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e6;
int arr[N];
int n;

void update(vector<int>& tree, int node, int s, int e, int idx) {
	if (s == e) ++tree[node];
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(tree, node * 2, s, mid, idx);
		else update(tree, node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(vector<int>& tree, int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return query(tree, node * 2, s, mid, L, R) + query(tree, node * 2 + 1, mid + 1, e, L, R);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> vals;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		vals.push_back(arr[i]);
	}

	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());

	int m = vals.size();
	vector<int> tree((m + 1) * 4, 0);

	for (int i = 0; i < n; ++i) {
		int cur = arr[i];
		int idx = lower_bound(vals.begin(), vals.end(), cur) - vals.begin();

		cout << query(tree, 1, 1, m, 1, idx) << "\n";
		update(tree, 1, 1, m, idx + 1);
	}
}