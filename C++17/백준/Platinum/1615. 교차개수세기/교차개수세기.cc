#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int N = 2001;
int n, m;
ll tree[N * 4];
vector<pii> edges;

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node]++;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

ll query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, L, R);
	ll right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		edges.push_back({ a, b });
	}
	sort(edges.begin(), edges.end());


	ll ans = 0;
	for (const pii& edge : edges) {
		ans += query(1, 1, n, edge.second + 1, n);
		update(1, 1, n, edge.second);
	}
	cout << ans;
}