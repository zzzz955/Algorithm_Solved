#include<iostream>
using namespace std;
using pii = pair<int, int>;

bool v[5][5];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int k, ans;

void print(const pii& j, const pii& h) {
	cout << "\n";
	for (int i = 0; i < 5; ++i) {
		for (int k = 0; k < 5; ++k) {
			if (j.first == h.first && j.second == h.second) cout << 'm';
			else if (i == j.first && k == j.second) cout << 'j';
			else if (i == h.first && k == h.second) cout << 'h';
			else cout << v[i][k];
		}
		cout << "\n";
	}
}

void bt(const pii& j, const pii& h, int remain) {
	if (remain <= 0) {
		if (j.first == h.first && j.second == h.second) ++ans;
		return;
	}
	if (j.first == h.first && j.second == h.second) return;
	//print(j, h);

	int jx = j.first, jy = j.second;
	int hx = h.first, hy = h.second;
	for (int i = 0; i < 4; ++i) {
		int njx = jx + dx[i], njy = jy + dy[i];

		if (njx < 0 || njx > 4 || njy < 0 || njy > 4 || v[njx][njy]) continue;
		for (int k = 0; k < 4; ++k) {
			int nhx = hx + dx[k], nhy = hy + dy[k];

			if (nhx < 0 || nhx > 4 || nhy < 0 || nhy > 4 || v[nhx][nhy]) continue;
			v[njx][njy] = true;
			v[nhx][nhy] = true;
			bt({ njx, njy }, { nhx, nhy }, remain - 2);
			v[njx][njy] = false;
			v[nhx][nhy] = false;
		}
	}
}

int main() {
	int apple = 25;

	cin >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		v[--x][--y] = true;
		--apple;
	}

	v[0][0] = true, v[4][4] = true;
	bt({ 0, 0 }, { 4, 4 }, apple - 2);
	cout << ans;
}