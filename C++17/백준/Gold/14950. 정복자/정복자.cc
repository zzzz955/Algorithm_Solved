#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, t;
struct Edge {
	int sn, dn, w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};
vector<Edge> edges;
int nodes[100001];

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	for (int i = 0; i < n; ++i) nodes[i] = i;
	while (m--) {
		int sn, dn, w; cin >> sn >> dn >> w;
		if (sn > dn) swap(sn, dn);
		edges.push_back({ sn, dn, w });
	}

	sort(edges.begin(), edges.end());
	int dist = 0;
	int cnt = 0;
	for (int i = 0; i < edges.size(); ++i) {
		const Edge& edge = edges[i];
		int sn = edge.sn, dn = edge.dn, w = edge.w;
		int A = Find(sn);
		int B = Find(dn);
		if (A == B) continue;
		nodes[B] = A;
		dist += w + t * cnt;
		cnt++;
	}
	cout << dist;
}