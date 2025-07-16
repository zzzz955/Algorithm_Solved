#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
//#include<algorithm>
using namespace std;

const int N = 1002;
int n, k;
struct Edge {
	int nn, nv;
	//bool operator<(const Edge& other) const {
	//	return nv < other.nv;
	//}
};
vector<Edge> edges[N];
struct Pos {
	int x, y;
};
Pos poses[N];
struct PF {
	int cn, cv, ck, cf;
	bool operator<(const PF& other) const {
		return cv > other.cv;
	}
};

int get_fuel(int x1, int y1, int x2, int y2) {
	double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	int div = dist / 10;
	return dist > div ? div + 1 : div;
}

bool dijkstra(int mf) {
	priority_queue<PF> pq;
	pq.push({ 0, 0, 0, mf });
	vector<int> dist(n + 2, 2e9);
	dist[0] = 0;

	while (!pq.empty()) {
		PF pf = pq.top(); pq.pop();
		int cn = pf.cn, cv = pf.cv, ck = pf.ck, cf = pf.cf;
		//cout << cn << " " << cv << " " << ck << " " << cf << " " << mf << "\n";
		if (dist[cn] < cv) continue;
		if (cn == n + 1) return true;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nv = cv + edge.nv, nk = ck, nf = cf - edge.nv;
			if (edge.nv > mf) continue;
			if (nf < 0) {
				nf = mf - edge.nv;
				nk++;
			}
			if (nk > k) continue;
			if (dist[nn] > nv) {
				dist[nn] = nv;
				pq.push({ nn, nv, nk, nf });
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		poses[i] = { x, y };

		for (int j = 0; j < i; ++j) {
			int fuel = get_fuel(poses[j].x, poses[j].y, x, y);
			edges[i].push_back({ j, fuel });
			edges[j].push_back({ i, fuel });
		}

		int fuel = get_fuel(10000, 10000, x, y);
		edges[n + 1].push_back({ i, fuel });
		edges[i].push_back({ n + 1, fuel });
	}

	//for (int i = 0; i <= n + 1; ++i) sort(edges[i].begin(), edges[i].end());

	int l = 0, r = 1500;
	while (l <= r) {
		int mid = (l + r) / 2;
		bool success = dijkstra(mid);
		if (success) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;
}