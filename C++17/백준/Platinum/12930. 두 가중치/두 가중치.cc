#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 20;
int n;
struct Edge {
	int nv1, nv2;
};
struct Pos {
	int cn, cv1, cv2;
	bool operator<(const Pos& other) const {
		return cv1 * cv2 > other.cv1 * other.cv2;
	}
};
Edge edges[N][N];

void get_edges(int index) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char ch; cin >> ch;
			if (ch == '.') continue;

			int w = ch - '0';
			if (index == 1) edges[i][j].nv1 = w;
			else edges[i][j].nv2 = w;
		}
	}
}

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, 0 });
	vector<vector<int>> dist(n, vector<int>(200, 2e9));
	dist[0][0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.cn, cv1 = pos.cv1, cv2 = pos.cv2;
		//cout << cn << " " << cv1 << " " << cv2 << "\n";
		if (cv1 >= 200 || cv2 >= 200) continue;
		if (dist[cn][cv2] < cv1) continue;
		

		for (int i = 0; i < n; ++i) {
			const Edge& edge = edges[cn][i];
			if (!edge.nv1) continue;
			int nv1 = edge.nv1 + cv1, nv2 = edge.nv2 + cv2;
			if (nv1 >= 200 || nv2 >= 200) continue;

			if (dist[i][nv2] > nv1) {
				dist[i][nv2] = nv1;
				pq.push({ i, nv1, nv2 });
			}
		}
	}

	//cout << "done\n";
	int ans = 2e9;
	for (int i = 0; i < 200; ++i) {
		if (dist[1][i] == 2e9) continue;
		//cout << i << " " << dist[1][i] << "\n";
		ans = min(ans, i * dist[1][i]);
	}
	return ans == 2e9 ? -1 : ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	get_edges(1);
	get_edges(2);
	cout << dijkstra();
}