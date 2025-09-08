#include<iostream>
#include<cstring>
using namespace std;

const int N = 30;
int n, m, r, a;
bool lst[N][N];
bool v[N][N];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bt(int x, int y, int s, int t) {
	if (t >= a) return;
	if (s == r) {
		a = t;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		int move = 0;
		while (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && !lst[nx][ny]) {
			v[nx][ny] = true;
			nx += dx[i];
			ny += dy[i];
			move++;
		}

		if (!move) continue;
		
		int j = (i + 2) % 4;
		nx += dx[j];
		ny += dy[j];
		bt(nx, ny, s + move, t + 1);
		while (move--) {
			v[nx][ny] = false;
			nx += dx[j];
			ny += dy[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int idx = 1;
	while (cin >> n) {
		cin >> m;
		memset(lst, false, sizeof(lst));
		r = n * m;
		a = 2e9;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char c; cin >> c;
				if (c == '*') {
					lst[i][j] = true;
					r--;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (lst[i][j]) continue;
				v[i][j] = true;
				bt(i, j, 1, 0);
				v[i][j] = false;
			}
		}
		cout << "Case " << idx++ << ": " << (a == 2e9 ? -1 : a) << "\n";
	}
}