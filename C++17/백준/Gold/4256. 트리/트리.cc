#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int N = 1000;
int t, n, idx;
int pre[N];
unordered_map<int, int> dic;
vector<int> post;

void build(int L, int R) {
	if (L > R) return;
	int root = pre[idx++];
	int iroot = dic[root];

	build(L, iroot - 1);
	build(iroot + 1, R);
	post.push_back(root);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		dic.clear();
		post.clear();
		idx = 0;
		
		for (int i = 0; i < n; ++i) cin >> pre[i];
		for (int i = 0; i < n; ++i) {
			int a; cin >> a;
			dic[a] = i;
		}

		build(0, n - 1);
		for (int i = 0; i < n; ++i) {
			cout << post[i];
			if (i != n - 1) cout << " ";
		}
		if (t) cout << "\n";
	}
}