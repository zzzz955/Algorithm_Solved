#include<iostream>
#define ll long long
using namespace std;

const int N = 100000;
int t, n, k;
int lst[N];
ll presum[N * 4];
struct T {
	ll SUM;
	int MAX, MIN;
};
T tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = { lst[s], lst[s], lst[s] };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node].SUM = tree[node * 2].SUM + tree[node * 2 + 1].SUM;
		tree[node].MAX = max(tree[node * 2].MAX, tree[node * 2 + 1].MAX);
		tree[node].MIN = min(tree[node * 2].MIN, tree[node * 2 + 1].MIN);
	}
}

void update(int node, int s, int e, int idx, int val) {
	if (s == e) tree[node] = { val, val, val };
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node].SUM = tree[node * 2].SUM + tree[node * 2 + 1].SUM;
		tree[node].MAX = max(tree[node * 2].MAX, tree[node * 2 + 1].MAX);
		tree[node].MIN = min(tree[node * 2].MIN, tree[node * 2 + 1].MIN);
	}
}

ll sumQuery(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node].SUM;
	int mid = (s + e) / 2;
	ll left = sumQuery(node * 2, s, mid, L, R);
	ll right = sumQuery(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int maxQuery(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return -1;
	if (L <= s && e <= R) return tree[node].MAX;
	int mid = (s + e) / 2;
	int left = maxQuery(node * 2, s, mid, L, R);
	int right = maxQuery(node * 2 + 1, mid + 1, e, L, R);
	return max(left, right);
}

int minQuery(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 1e5 + 1;
	if (L <= s && e <= R) return tree[node].MIN;
	int mid = (s + e) / 2;
	int left = minQuery(node * 2, s, mid, L, R);
	int right = minQuery(node * 2 + 1, mid + 1, e, L, R);
	return min(left, right);
}

int getVal(int node, int s, int e, int idx) {
	if (s == e) return tree[node].SUM;
	int mid = (s + e) / 2;
	if (idx <= mid) return getVal(node * 2, s, mid, idx);
	return getVal(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; ++i) {
			lst[i] = i;
			presum[i] = presum[i - 1] + lst[i];
		}
		build(1, 0, n - 1);

		while (k--) {
			int op, a, b; cin >> op >> a >> b;
			if (op) {
				ll range = presum[b] - (a > 0 ? presum[a - 1] : 0);
				ll SUM = sumQuery(1, 0, n - 1, a, b);
				int MAX = maxQuery(1, 0, n - 1, a, b);
				int MIN = minQuery(1, 0, n - 1, a, b);
				//cout << SUM << " " << MAX << " " << MIN << "\n";
				if (range == SUM && MIN == a && MAX == b) cout << "YES\n";
				else cout << "NO\n";
			}
			else {
				int A = getVal(1, 0, n - 1, a);
				int B = getVal(1, 0, n - 1, b);
				update(1, 0, n - 1, a, B);
				update(1, 0, n - 1, b, A);
			}
		}
	}
}