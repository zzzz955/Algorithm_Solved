#include<iostream>
#define ll long long
using namespace std;

const int N = 3e5 + 1;
int n, q;
int odd[N];
int even[N];
ll to[N * 4];
ll te[N * 4];

void build(int node, int s, int e) {
	if (s == e) {
		if (s % 2) to[node] = odd[s];
		else te[node] = even[s];
	}
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		to[node] = to[node * 2] + to[node * 2 + 1];
		te[node] = te[node * 2] + te[node * 2 + 1];
	}
}

void update(int node, int s, int e, int idx, int val) {
	if (s == e) {
		if (s % 2) to[node] += val;
		else te[node] += val;
	}
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		to[node] = to[node * 2] + to[node * 2 + 1];
		te[node] = te[node * 2] + te[node * 2 + 1];
	}
}

ll oddQuery(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return to[node];
	int mid = (s + e) / 2;
	ll left = oddQuery(node * 2, s, mid, L, R);
	ll right = oddQuery(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

ll evenQuery(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return te[node];
	int mid = (s + e) / 2;
	ll left = evenQuery(node * 2, s, mid, L, R);
	ll right = evenQuery(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		if (i % 2) cin >> odd[i];
		else cin >> even[i];
	}

	build(1, 1, n);
	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			ll L = oddQuery(1, 1, n, b, c);
			ll R = evenQuery(1, 1, n, b, c);
			cout << abs(L - R) << "\n";
		}
		else update(1, 1, n, b, c);
	}
}