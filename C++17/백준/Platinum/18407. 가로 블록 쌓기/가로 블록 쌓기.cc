#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
using pii = pair<int, int>;

const int N = 1e5;
int n;
map<int, int> xs;
pii qs[N];
vector<int> tree;
vector<int> lazy;

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] = lazy[node];

		if (s != e) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}

		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int x) {
	if (R < s || e < L) return;
	propagate(node, s, e);
	if (L <= s && e <= R) {
		lazy[node] = x;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, x);
	update(node * 2 + 1, mid + 1, e, L, R, x);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	propagate(node, s, e);
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return max(query(node * 2, s, mid, L, R), query(node * 2 + 1, mid + 1, e, L, R));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int w, d; cin >> w >> d;
		int s = d, e = d + w - 1;
		xs[s];
		xs[e];
		qs[i] = { s, e };
	}

	int idx = 0;
	for (auto& x : xs) x.second = ++idx;
	int len = xs.size();
	tree.resize((len + 1) * 4, 0);
	lazy.resize((len + 1) * 4, 0);

	for (int i = 0; i < n; ++i) {
		int L = xs[qs[i].first], R = xs[qs[i].second];
		//cout << L << " " << R << "\n";
		int mx = query(1, 1, len, L, R);
		update(1, 1, len, L, R, mx + 1);
	}
	cout << query(1, 1, len, 1, len);
}