#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
using pii = pair<int, int>;

const int N = 2e4 + 1;
int n;
vector<pii> cs;
vector<int> xs;
int tree[N * 4];
int lazy[N * 4];
set<int> ans;

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

void update(int node, int s, int e, int L, int R, int v) {
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] = v;
		propagate(node, s, e);
		return;
	}
	propagate(node, s, e);
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, v);
	update(node * 2 + 1, mid + 1, e, L, R, v);
	tree[node] = tree[node * 2] == tree[node * 2 + 1] ? tree[node * 2] : 0;
}

void query(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (tree[node]) ans.insert(tree[node]);
	if (s == e) return;
	else {
		int mid = (s + e) / 2;
		query(node * 2, s, mid, L, R);
		query(node * 2 + 1, mid + 1, e, L, R);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int l, r; cin >> l >> r;
		cs.push_back({ l, r });
		xs.push_back(l);
		xs.push_back(r);
	}

	xs.push_back(0);
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	int m = xs.size();
	for (int i = 1; i <= n; ++i) {
		pii c = cs[i - 1];
		int l = c.first, r = c.second;
		int li = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
		int ri = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
		update(1, 1, m, li, ri, i);
	}
	query(1, 1, m, 1, m);
	if (ans.count(0)) ans.erase(0);
	cout << ans.size();
}