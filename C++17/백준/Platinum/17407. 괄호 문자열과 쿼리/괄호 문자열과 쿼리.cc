#include<iostream>
using namespace std;

const int N = 1e5 + 1;
struct Node {
	int o, c;
};
Node tree[N * 4];
Node lst[N];
string s;
int n, m;

void build(int node, int s, int e) {
	if (s == e) tree[node] = lst[s];
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);

		Node L = tree[node * 2], R = tree[node * 2 + 1];		
		int del = min(L.o, R.c);
		tree[node] = { L.o + R.o - del, L.c + R.c - del };
	}
}

void update(int node, int s, int e, int idx, Node val) {
	if (s == e) tree[node] = val;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);

		Node L = tree[node * 2], R = tree[node * 2 + 1];
		int del = min(L.o, R.c);
		tree[node] = { L.o + R.o - del, L.c + R.c - del };
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; ++i) {
		char c = s[i - 1];
		if (c == '(') lst[i] = { 1, 0 };
		else lst[i] = { 0, 1 };
	}
	build(1, 1, n);

	cin >> m;
	int cnt = 0;
	while (m--) {
		int i; cin >> i;

		if (lst[i].o) lst[i] = { 0, 1 };
		else lst[i] = { 1, 0 };

		update(1, 1, n, i, lst[i]);
		if (!tree[1].c && !tree[1].o) ++cnt;
	}
	cout << cnt;
}