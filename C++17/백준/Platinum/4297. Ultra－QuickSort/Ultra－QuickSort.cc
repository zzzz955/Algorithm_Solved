#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 5e5;
int n;
vector<int> a, c;
vector<int> tree;

void update(int node, int s, int e, int idx) {
	if (s == e) ++tree[node];
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
	cout.tie(0);

	a.reserve(N);
	c.reserve(N);
	tree.reserve(N * 4);

	while (cin >> n && n) {
		a.clear();
		c.clear();
		tree.clear();

		for (int i = 0; i < n; ++i) {
			int d; cin >> d;
			a.push_back(d);
			c.push_back(d);
		}

		sort(c.begin(), c.end());
		c.erase(unique(c.begin(), c.end()), c.end());
		int m = c.size();
		tree.resize(m * 4, 0);

		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			int idx = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
			ans += query(1, 0, m - 1, idx, m);
			//cout << a[i] << " " << idx << "\n";
			update(1, 0, m - 1, idx);
		}
		cout << ans << "\n";
	}
}