#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int N = 101;
vector<int> edges[N];
struct Pos {
	double x, y;
};
Pos lst[N];
int vt[N];
int match[N];
int t;
int n, m, s, v;

double getDist(double x1, double x2, double y1, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool dfs(int cn) {
	for (int nn : edges[cn]) {
		if (vt[nn] == t) continue;
		vt[nn] = t;
		if (!match[nn] || dfs(match[nn])) {
			match[nn] = cn;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s >> v;
	for (int i = 1; i <= n; ++i) {
		double x, y; cin >> x >> y;
		lst[i] = { x, y };
	}

	for (int i = 1; i <= m; ++i) {
		double x, y; cin >> x >> y;
		for (int j = 1; j <= n; ++j) {
			Pos pos = lst[j];
			double dist = getDist(x, pos.x, y, pos.y);
			if (dist <= s * v) edges[j].push_back(i);
		}
	}

	int hide = 0;
	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfs(i)) hide++;
	}
	cout << n - hide;
}