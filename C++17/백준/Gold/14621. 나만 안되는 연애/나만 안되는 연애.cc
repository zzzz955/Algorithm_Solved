#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1001;
int n, m;
bool gender[N];
int group[N];
struct Edge {
	int f, t, w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};
vector<Edge> edges;

int Find(int a) {
	if (group[a] == a) return a;
	return group[a] = Find(group[a]);
}

bool Union(int a, int b) {
	int A = Find(a), B = Find(b);
	if (A == B) return false;
	group[B] = A;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		char c; cin >> c;
		if (c == 'W') gender[i] = true;
	}

	while (m--) {
		int f, t, w; cin >> f >> t >> w;
		if (gender[f] == gender[t]) continue;
		edges.push_back({ f, t, w });
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; ++i) group[i] = i;

	int sum = 0, cnt = 0;
	for (const Edge& edge : edges) {
		int f = edge.f, t = edge.t, w = edge.w;
		if (Union(f, t)) {
			sum += w;
			++cnt;
		}
	}
	cout << (cnt == n - 1 ? sum : -1);
}