#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 50;
const int C = 1 << 7;
unordered_map<char, short> dic;
int n;
struct Edge {
	int f, t, v;
	bool operator<(const Edge& other) const {
		return v < other.v;
	}
};
vector<Edge> edges;
int nodes[N];

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return false;
	nodes[B] = A;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int idx = 1;
	for (char i = 'a'; i <= 'z'; ++i) dic[i] = idx++;
	for (char i = 'A'; i <= 'Z'; ++i) dic[i] = idx++;
	
	int total = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c; cin >> c;
			if (c == '0') continue;
			total += dic[c];
			if (i == j) continue;
			edges.push_back({ i, j, dic[c] });
		}
	}

	sort(edges.begin(), edges.end());
	for (int i = 0; i < n; ++i) nodes[i] = i;

	int cnt = 0, cost = 0;
	for (const Edge& edge : edges) {
		int f = edge.f, t = edge.t, v = edge.v;
		if (Union(f, t)) {
			//cout << f << " " << t << " " << v << "\n";
			cnt++;
			cost += v;
		}
	}

	if (cnt < n - 1) cout << -1;
	else cout << total - cost;
}