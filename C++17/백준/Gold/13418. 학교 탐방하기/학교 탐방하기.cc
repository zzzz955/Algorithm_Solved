#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int N = 1e3 + 5;
int n, m;
struct Edge {
	int cn, nn, v;
};
bool best(const Edge& left, const Edge& right) {
	return left.v < right.v;
}
bool worst(const Edge& left, const Edge& right) {
	return left.v > right.v;
}
vector<Edge> edges;
int w[N];
int nodes[N];

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return false;
	if (A > B) swap(A, B);
	nodes[B] = A;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	++m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({ a, b, !c });
		edges.push_back({ b, a, !c });
	}

	for (int i = 0; i <= n; ++i) nodes[i] = i;
	int best_val = 0, best_conn = 0;
	sort(edges.begin(), edges.end(), best);
	for (const Edge& edge : edges) {
		int A = Find(edge.cn);
		int B = Find(edge.nn);
		if (A != B) {
			Union(A, B);
			best_val += edge.v;
			best_conn++;
		}
		if (best_conn == n) break;
	}

	for (int i = 0; i <= n; ++i) nodes[i] = i;
	int worst_val = 0, worst_conn = 0;
	sort(edges.begin(), edges.end(), worst);
	for (const Edge& edge : edges) {
		if (Union(edge.cn, edge.nn)) {
			worst_val += edge.v;
			worst_conn++;
		}
		if (worst_conn == n) break;
	}

	cout << pow(worst_val, 2) - pow(best_val, 2);
}