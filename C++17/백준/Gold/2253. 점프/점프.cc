#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e4 + 1;
const int J = 140;
int n, m;
bool j[N][J];
bool cant[N];
struct Pos {
	int x, t, pj;
};
int dx[] = { -1, 0, 1 };

int bfs() {
	queue<Pos> q;
	q.push({ 1, 0 });

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, ct = pos.t, pj = pos.pj;
		//cout << cx << " " << ct << " " << pj << "\n";
		if (cx == n) return ct;

		for (int i = 0; i < 3; ++i) {
			int jump = pj + dx[i];
			if (jump <= 0) continue;
			
			int nx = cx + jump;
			if (1 <= nx && nx <= n && !cant[nx] && !j[nx][jump]) {
				j[nx][jump] = true;
				q.push({ nx, ct + 1, jump });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int x; cin >> x;
		cant[x] = true;
	}

	cout << bfs();
}