#include<iostream>
#include<set>
using namespace std;

const int N = 100001;
int n, s;
set<int> lst[N];
int it[N];
int ot[N];
int t;
bool v[N];

void dfs(int node) {
	it[node] = ++t;
	for (int i : lst[node]) {
		if (v[i]) continue;
		v[i] = true;
		dfs(i);
	}
	ot[node] = ++t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int node; cin >> node;
		while (1) {
			int v; cin >> v;
			if (v == -1) break;
			lst[node].insert(v);
		}
	}
	cin >> s;
	v[s] = true;
	dfs(s);
	for (int i = 1; i <= n; ++i) {
		cout << i << " " << it[i] << " " << ot[i] << "\n";
	}
}