#include<iostream>
#include<unordered_map>
using namespace std;
using pii = pair<int, int>;

const int N = 2e5 + 1;
int t, n;
int lst[N];
int tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = lst[s];
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return max(query(node * 2, s, mid, L, R), query(node * 2 + 1, mid + 1, e, L, R));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		unordered_map<int, pii> dic;
		for (int i = 1; i <= n; ++i) {
			int a; cin >> a;
			lst[i] = a;
			if (dic.count(a)) dic[a].second = i;
			else dic[a] = { i, i };
		}

		build(1, 1, n);
		bool flag = true;
		for (const auto& d : dic) {
			const pii& p = d.second;
			int res = query(1, 1, n, p.first, p.second);
			if (res > d.first) {
				flag = false;
				break;
			}
		}

		cout << (flag ? "Yes\n" : "No\n");
	}
}