#include<iostream>
#include<vector>
using namespace std;

const int N = 10;
int n, m, h, ans, mx;
int lst[N];
bool v[N];
struct Pos {
	int x, y;
};
vector<Pos> milks;
int hx, hy;

int get_dist(int cx, int cy, int dx, int dy) {
	return abs(dy - cy) + abs(dx - cx);
}

void bt(int level, int cnt, int ch, int cx, int cy) {
	int dist = get_dist(cx, cy, hx, hy);
	if (dist <= ch) ans = max(ans, cnt);
	if (level == mx) return;

	for (int i = 0; i < mx; ++i) {
		if (v[i]) continue;

		const Pos& pos = milks[i];
		int nx = pos.x, ny = pos.y;

		int dist = get_dist(cx, cy, nx, ny);
		//cout << cx << " " << cy << " " << nx << " " << ny << " " << dist << "\n";
		if (dist <= ch) {
			v[i] = true;
			bt(level + 1, cnt + 1, ch - dist + h, nx, ny);
			v[i] = false;
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int k; cin >> k;
			if (k == 2) milks.push_back({ i, j });
			else if (k == 1) hx = i, hy = j;
		}
	}

	mx = milks.size();
	bt(0, 0, m, hx, hy);
	cout << ans;
}