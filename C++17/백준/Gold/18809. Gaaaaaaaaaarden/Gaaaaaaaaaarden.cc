#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
using namespace std;

int N, M, G, R, ans;
vector<vector<int>> lst;
vector<int> Gs, Rs;
struct Pos {
	int x, y, c;
};
int land;
Pos lands[10];
bool landsV[10];
unordered_map<int, int> simV;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void print(const vector<vector<int>>& temp) {
	cout << "\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << temp[i][j] << " ";
		}
		cout << "\n";
	}
}

int floodFill() {
	queue<Pos> q1;
	unordered_map<int, int> spread;
	vector<vector<int>> temp = lst;

	for (int i : Gs) {
		q1.push({ lands[i].x, lands[i].y, 3 });
		temp[lands[i].x][lands[i].y] = 3;
	}
	for (int i : Rs) {
		q1.push({ lands[i].x, lands[i].y, 4 });
		temp[lands[i].x][lands[i].y] = 4;
	}
	
	int F = 0;
	while (!q1.empty()) {
		//print(temp);
		queue<Pos> q2;
		swap(q1, q2);
		while (!q2.empty()) {
			Pos pos = q2.front(); q2.pop();
			int cx = pos.x, cy = pos.y, cc = pos.c;

			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i], ny = cy + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && temp[nx][ny] == 1) {
					int idx = nx * M + ny;
					if (!spread[idx]) spread[idx] = cc;
					else if (spread[idx] != cc) spread[idx] = 5;
					else continue;
				}
			}
		}
		for (const auto& d : spread) {
			int x = d.first / M, y = d.first % M;
			temp[x][y] = d.second;
			if (d.second != 5) q1.push({ x, y, d.second });
			else F++;
		}
		spread.clear();
	}
	return F;
}

void bt(int Gc, int Rc) {
	if (Gc == G && Rc == R) {
		ans = max(ans, floodFill());
		return;
	}
	if (Gc < G) {
		int def = 0;
		if (!Gs.empty()) def = Gs.back();
		for (int i = def; i < land; ++i) {
			if (landsV[i]) continue;
			landsV[i] = 1;
			Gs.push_back(i);
			bt(Gc + 1, Rc);
			landsV[i] = 0;
			Gs.pop_back();
		}
	}
	else if (Rc < R) {
		int def = 0;
		if (!Rs.empty()) def = Rs.back();
		for (int i = def; i < land; ++i) {
			if (landsV[i]) continue;
			landsV[i] = 1;
			Rs.push_back(i);
			bt(Gc, Rc + 1);
			landsV[i] = 0;
			Rs.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> G >> R;
	lst.resize(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> lst[i][j];
			if (lst[i][j] == 2) {
				lands[land++] = { i, j };
				lst[i][j] = 1;
			}
		}
	}
	bt(0, 0);
	cout << ans;
}