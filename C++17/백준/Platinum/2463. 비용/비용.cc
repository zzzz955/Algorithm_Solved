#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 1e5 + 1;
const ll MOD = 1e9;
int n, m;
ll ans, total;
struct Edge {
	int u, v;
	ll c;
	bool operator<(const Edge& other) const {
		return c > other.c;
	}
};
vector<Edge> edges;
int nodes[N];
ll sizes[N];

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	if (sizes[A] < sizes[B]) swap(A, B);
	nodes[B] = A;

	ll c = (sizes[A] % MOD) * (sizes[B] % MOD) % MOD;
	c = c * (total % MOD) % MOD;
	ans = (ans + c) % MOD;

	sizes[A] += sizes[B];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		nodes[i] = i;
		sizes[i] = 1;
	}

	while (m--) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		edges.push_back({ u, v, c });
		total += c;
	}

	sort(edges.begin(), edges.end());
	for (const Edge& edge : edges) {
		int u = edge.u, v = edge.v, c = edge.c;
		Union(u, v);
		total -= c;
		
	}
	cout << ans;
}