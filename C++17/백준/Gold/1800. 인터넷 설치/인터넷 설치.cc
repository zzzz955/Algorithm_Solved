#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1001;
int n, p, k;
struct Edge {
	int nn, nv;
};
vector<Edge> edges[N];
struct Pos {
	int cn, cv, cs;
	bool operator<(const Pos& other) const {
		return cv > other.cv;
	}
};

bool dijkstra(int mv) {
	priority_queue<Pos> pq;
	pq.push({ 1, 0, 0 });
	vector<vector<int>> dist(n + 1, vector<int>(k + 1, mv + 1));
	dist[1][0] = 0;
	//cout << mv << "\n";

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv = pos.cv, cs = pos.cs;
		//cout << cn << " " << cv << " " << cs << "\n";
		if (dist[cn][cs] < cv) continue;
		if (cn == n) return true;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = max(cv, edge.nv), ns = cs;
			if (nv > mv) {
				if (ns < k) {
					ns++;
					nv = cv;
				}
				else continue;
			}

			if (dist[nn][ns] > nv) {
				for (int i = ns; i <= k; ++i) {
					if (dist[nn][i] > nv) dist[nn][i] = nv;
				}
				pq.push({ nn, nv, ns });
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> k;
	while (p--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	int l = 0, r = 1000001;
	while (l <= r) {
		int mid = (l + r) / 2;
		bool res = dijkstra(mid);
		if (res) r = mid - 1;
		else l = mid + 1;
	}
	cout << (l > 1000000 ? -1 : l);
}