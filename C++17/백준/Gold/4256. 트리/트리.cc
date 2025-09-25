#include<iostream>
#include<vector>
using namespace std;

const int N = 1002;
int t, n;
int pre_idx, post_idx;
int pre[N], in[N], post[N];

void build(int L, int R) {
	if (L > R) return;
	int root = pre[pre_idx++];
	int iroot = in[root];

	build(L, iroot - 1);
	build(iroot + 1, R);
	post[post_idx++] = root;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		pre_idx = post_idx = 1;
		
		for (int i = 1; i <= n; ++i) cin >> pre[i];
		for (int i = 1; i <= n; ++i) {
			int a; cin >> a;
			in[a] = i;
		}

		build(1, n);
		for (int i = 1; i <= n; ++i) {
			cout << post[i];
			if (i < n) cout << " ";
		}
		if (t) cout << "\n";
	}
}