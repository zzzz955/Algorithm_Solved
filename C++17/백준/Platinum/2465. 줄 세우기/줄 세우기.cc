#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

const int N = 1e5;
int n;
int lst[N];
int order[N];
int tree[N * 4];
multiset<int> dic;

void build(int node, int s, int e) {
	if (s == e) tree[node]++;
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node]--;
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
	if (tree[node * 2] > val) return query(node * 2, s, mid, val);
	return query(node * 2 + 1, mid + 1, e, val - tree[node * 2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	sort(lst, lst + n);
	build(1, 0, n - 1);

	for (int i = 0; i < n; ++i) cin >> order[i];

	vector<int> ans;
	for (int i = n - 1; i >= 0; --i) {
		int val = order[i];
		int idx = query(1, 0, n - 1, val);
		//cout << val << " " << idx << "\n";
		update(1, 0, n - 1, idx);
		ans.push_back(lst[idx]);
	}

	for (int i = n - 1; i >= 0; --i) cout << ans[i] << "\n";
}