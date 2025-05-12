#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<bool> lst1(2e5, true), lst2(2e5, true);
vector<bool> v1(2e5, false), v2(2e5, false);
int n, k;
struct Pos {
	bool x;
	int y, t;
};

bool bfs() {
	queue<Pos> q;
	q.push({ false, 0, 0 });
	v1[0] = true;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		bool cx = pos.x;
		int cy = pos.y, ct = pos.t;
		if (cy >= n) return true;

		if (!cx) {
			if (cy + 1 > ct && lst1[cy + 1] && !v1[cy + 1]) {
				v1[cy + 1] = true;
				q.push({ false, cy + 1, ct + 1 });
			}
			if (cy + k > ct && lst2[cy + k] && !v2[cy + k]) {
				v2[cy + k] = true;
				q.push({ true, cy + k, ct + 1 });
			}
			if (cy - 1 > ct && lst1[cy - 1] && !v1[cy - 1]) {
				v1[cy - 1] = true;
				q.push({ false, cy - 1, ct + 1 });
			}
		}
		else {
			if (cy + 1 > ct && lst2[cy + 1] && !v2[cy + 1]) {
				v2[cy + 1] = true;
				q.push({ true, cy + 1, ct + 1 });
			}
			if (cy + k > ct && lst1[cy + k] && !v1[cy + k]) {
				v1[cy + k] = true;
				q.push({ false, cy + k, ct + 1 });
			}
			if (cy - 1 > ct && lst2[cy - 1] && !v2[cy - 1]) {
				v2[cy - 1] = true;
				q.push({ true, cy - 1, ct + 1 });
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		char ch; cin >> ch;
		lst1[i] = ch - '0';
	}
	for (int i = 0; i < n; ++i) {
		char ch; cin >> ch;
		lst2[i] = ch - '0';
	}

	cout << bfs();
}