#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int n;
struct Q1 {
	int i, j, k;
};
struct Q2 {
	int i, j, k, idx;
	bool operator<(const Q2& other) const {
		return k > other.k;
	}
};
vector<ll> tree;
vector<ll> lazy;
vector<int> cs;

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += lazy[node] * (cs[e + 1] - cs[s]);
		
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] += val;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, val);
	update(node * 2 + 1, mid + 1, e, L, R, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, L, R) + query(node * 2 + 1, mid + 1, e, L, R);
}

pair<int, int> get_range(int i, int j) {
	int L = lower_bound(cs.begin(), cs.end(), i) - cs.begin();
	int R = lower_bound(cs.begin(), cs.end(), j + 1) - cs.begin();
	return { L, R - 1 };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	queue<Q1> q1;
	priority_queue<Q2> q2;
	int q2_cnt = 0;
	vector<ll> ans;
	
	while (n--) {
		int o, i, j, k; cin >> o >> i >> j >> k;
		cs.push_back(i);
		cs.push_back(j + 1);
		if (o == 1) q1.push({ i, j, k });
		else q2.push({ i, j, k, q2_cnt++ });
	}

	sort(cs.begin(), cs.end());
	cs.erase(unique(cs.begin(), cs.end()), cs.end());
	int m = cs.size();

	tree.resize(m * 4, 0);
	lazy.resize(m * 4, 0);
	ans.resize(q2_cnt, 0);
	int q1_cnt = 0;
	while (!q1.empty() || !q2.empty()) {
		if (!q2.empty() && q2.top().k == q1_cnt) {
			Q2 q = q2.top(); q2.pop();
			int i = q.i, j = q.j, k = q.k;

			auto [L, R] = get_range(i, j);
			ans[q.idx] = query(1, 0, m - 2, L, R);
			continue;
		}

		if (!q1.empty()) {
			++q1_cnt;
			Q1 q = q1.front(); q1.pop();
			int i = q.i, j = q.j, k = q.k;

			auto [L, R] = get_range(i, j);
			update(1, 0, m - 2, L, R, k);
		}
	}
	for (ll i : ans) cout << i << "\n";
}