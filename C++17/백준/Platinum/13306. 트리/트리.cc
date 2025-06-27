#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 1;
int n, q;
int par[N];
int nodes[N];
struct Query {
	int op, v1, v2;
};

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	nodes[B] = A;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;

	nodes[1] = 1;
	for (int i = 2; i <= n; ++i) {
		cin >> par[i];
		nodes[i] = i;
	}

	vector<Query> queries;
	for (int i = 0; i < q + n - 1; ++i) {
		int op;  cin >> op;

		if (op) {
			int v1, v2; cin >> v1 >> v2;
			queries.push_back({ op, v1, v2 });
		}
		else {
			int v1; cin >> v1;
			queries.push_back({ op, v1 });
		}
	}

	vector<string> res;
	while (!queries.empty()) {
		Query query = queries.back(); queries.pop_back();
		
		if (query.op) {
			if (Find(query.v1) == Find(query.v2)) res.push_back("YES\n");
			else res.push_back("NO\n");
		}
		else Union(par[query.v1], query.v1);
	}

	for (int i = res.size() - 1; i >= 0; --i) cout << res[i];
}