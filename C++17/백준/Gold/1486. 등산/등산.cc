#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int n, m, t, d;
int lst[25][25];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y, v;
	bool operator<(const Pos& other) const {
		return v > other.v;
	}
};
struct bPos {
	int h, x, y, v;
	bool operator<(const bPos& other) const {
		return h > other.h;
	}
};
vector<bPos> dest;

void go() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, 0 });
	vector<vector<int>> dist(n, vector<int>(m, 2e9));
	dist[0][0] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cv = pos.v;
		if (dist[cx][cy] < cv) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && abs(lst[nx][ny] - lst[cx][cy]) <= t) {
				int nv = 1;
				if (lst[nx][ny] > lst[cx][cy]) nv = pow(lst[nx][ny] - lst[cx][cy], 2);
				if (cv + nv > d) continue;
				if (dist[nx][ny] > cv + nv) {
					dist[nx][ny] = cv + nv;
					pq.push({nx, ny, cv + nv});
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dist[i][j] != 2e9) dest.push_back({ lst[i][j], i, j, dist[i][j] });
		}
	}
}

bool back(bPos& bpos) {
	priority_queue<Pos> pq;
	pq.push({bpos.x, bpos.y, bpos.v});
	vector<vector<int>> dist(n, vector<int>(m, 2e9));
	dist[bpos.x][bpos.y] = bpos.v;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cv = pos.v;
		if (dist[cx][cy] < cv) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && abs(lst[nx][ny] - lst[cx][cy]) <= t) {
				int nv = 1;
				if (lst[nx][ny] > lst[cx][cy]) nv = pow(lst[nx][ny] - lst[cx][cy], 2);
				if (cv + nv > d) continue;
				if (!nx && !ny) return true;
				if (dist[nx][ny] > cv + nv) {
					dist[nx][ny] = cv + nv;
					pq.push({ nx, ny, cv + nv });
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if ('A' <= ch && ch <= 'Z') lst[i][j] = ch - 'A';
			else lst[i][j] = ch - 'a' + 26;
		}
	}

	go();
	sort(dest.begin(), dest.end());
	int ans = lst[0][0];
	for (bPos& bpos : dest) {
		if (back(bpos)) {
			ans = bpos.h;
			break;
		}
	}
	cout << ans;
}