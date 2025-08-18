#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

const int N = 5e5 + 1;
int n;
string lst[N];
struct Node {
	vector<int> c;
};
Node* nodes[N];
unordered_set<int> dic;

void dfs(int cn) {
	cout << lst[cn];
	for (int nn : nodes[cn]->c) dfs(nn);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> lst[i];
		nodes[i] = new Node;
		dic.insert(i);
	}

	int m = n - 1;
	while (m--) {
		int a, b; cin >> a >> b;
		nodes[a]->c.push_back(b);
		dic.erase(b);
	}
	dfs(*dic.begin());
}