#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int N = 17;
int n;
struct Pos {
	int x, y;
};
Pos poses[N];
struct Edge {
	int nn;
	double nv;
};
vector<Edge> edges[N];
double dp[1 << N][N];

double get_dist(const Pos& pos1, const Pos& pos2) {
	return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

double dfs(int mask, int cur) {
	if (mask == (1 << n) - 1) {
		double dist_to_start = get_dist(poses[cur], poses[1]);
		return dp[mask][cur] = dist_to_start;
	}

	if (dp[mask][cur] != -1.0f) return dp[mask][cur];

	dp[mask][cur] = 2e9;
	for (const Edge& edge : edges[cur]) {
		if (!(mask & (1 << edge.nn - 1))) {
			dp[mask][cur] = min(dp[mask][cur], dfs(mask | (1 << edge.nn - 1), edge.nn) + edge.nv);
		}
	}

	return dp[mask][cur];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		poses[i] = { x, y };
	}

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			const Pos& pos1 = poses[i];
			const Pos& pos2 = poses[j];
			double dist = get_dist(pos1, pos2);

			edges[i].push_back({ j, dist });
			edges[j].push_back({ i, dist });
		}
	}

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1.0f;
		}
	}

	cout << fixed;
	cout.precision(10);
	cout << dfs(1, 1);
}