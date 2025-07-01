#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e4 + 1;
int n, p;
int cost[N];
int nodes[N];
struct Edge {
	int s, e, c;
	bool operator<(const Edge& other) const {
		return c < other.c;
	}
};
vector<Edge> edges;

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
	cin >> n >> p;

	int mv = 2e9;
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
		mv = min(mv, cost[i]);
		nodes[i] = i;
	}

	while (p--) {
		int s, e, c; cin >> s >> e >> c;
		edges.push_back({ s, e, c * 2 + cost[s] + cost[e] });
	}

	sort(edges.begin(), edges.end());
	
	int sum = 0, cnt = 0;
	for (const Edge& edge : edges) {
		int s = edge.s, e = edge.e, c = edge.c;

		if (Union(s, e)) {
			sum += c;
			cnt++;
		}

		if (cnt == n - 1) break;
	}
	cout << sum + mv;
}