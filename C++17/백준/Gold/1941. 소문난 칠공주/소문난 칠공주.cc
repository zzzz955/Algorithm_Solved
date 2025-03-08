#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int ans;
int lst[25];
vector<int> choose;
bool way[5][5], v[5][5], pick[25];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y;
};

bool bfs() {
	memset(way, 0, sizeof(way));
	memset(v, 0, sizeof(v));

	for (int i : choose) {
		int x = i / 5, y = i % 5;
		way[x][y] = true;
	}

	int cnt = 1;
	queue<Pos> q;
	q.push({ choose[0] / 5, choose[0] % 5 });
	v[choose[0] / 5][choose[0] % 5] = true;
	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && way[nx][ny] && !v[nx][ny]) {
				v[nx][ny] = true;
				cnt++;
				q.push({ nx, ny });
			}
		}
	}
	return cnt == 7 ? true : false;
}

bool chk() {
	int cnt = 0;
	for (int i : choose) {
		if (lst[i]) cnt++;
	}
	return cnt >= 4 ? true : false;
}

void bt(int level, int cnt) {
	if (cnt == 7) {
		if (chk() && bfs()) ans++;
		return;
	}
	for (int i = level; i < 25; ++i) {
		if (pick[i]) continue;
		pick[i] = true;
		choose.push_back(i);
		bt(i + 1, cnt + 1);
		choose.pop_back();
		pick[i] = false;
	}
}

int main() {
	for (int i = 0; i < 5; ++i) {
		string s; cin >> s;
		for (int j = 0; j < 5; ++j) {
			if (s[j] == 'S') lst[i * 5 + j] = 1;
		}
	}
	bt(0, 0);
	cout << ans;
}