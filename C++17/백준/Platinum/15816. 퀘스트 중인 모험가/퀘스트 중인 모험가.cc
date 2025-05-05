#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int n, m;
struct Query {
	int op, arg1, arg2;
};
unordered_map<int, int> VI;
vector<int> tree;

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
	cout.tie(0);

	cin >> n;
	vector<int> lst;
	for (int i = 0; i < n; ++i) {
		int q; cin >> q;
		lst.push_back(q);
	}

	cin >> m;
	vector<Query> queries;
	for (int i = 0; i < m; ++i) {
		int op; cin >> op;
		if (op == 1) {
			int val; cin >> val;
			lst.push_back(val);
			queries.push_back({ op, val });
		}
		else {
			int L, R; cin >> L >> R;
			lst.push_back(L);
			lst.push_back(R);
			queries.push_back({ op, L, R });
		}
	}

	vector<int> sorted = lst;
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	int all = sorted.size();
	for (int i = 0; i < all; ++i) {
		VI[sorted[i]] = i;
	}

	tree.resize(all * 4);
	for (int i = 0; i < n; ++i) {
		update(1, 0, all - 1, VI[lst[i]]);
	}

	for (const Query& q : queries) {
		int op = q.op;
		if (op == 1) update(1, 0, all - 1, VI[q.arg1]);
		else {
			int cnt = query(1, 0, all - 1, VI[q.arg1], VI[q.arg2]);
			cout << q.arg2 - q.arg1 + 1 - cnt << "\n";
		}
	}
}