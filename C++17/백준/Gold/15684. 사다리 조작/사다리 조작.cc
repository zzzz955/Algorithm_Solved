#include<iostream>
using namespace std;

const int N = 21;
const int H = 31;
int n, m, h, ans = 4;
bool lst[H][N];
int dx[] = { 0, 0, 1 };
int dy[] = { -1, 1, 0 };

bool check() {
    for (int i = 1; i <= n; ++i) {
        int pos = i * 2;
        for (int j = 1; j <= h; ++j) {
            if (lst[j][pos - 1]) pos -= 2;
            else if (lst[j][pos + 1]) pos += 2;
        }
        if (pos != i * 2) return false;
    }
    return true;
}


void bt(int level, int x) {
    if (level >= ans) return;
    if (check()) {
        ans = level;
        return;
    }
    if (level == 3) return;

    for (int i = x; i <= h; ++i) {
        for (int j = 1; j < n; ++j) {
            int col = j * 2 + 1;
            if (lst[i][col] || lst[i][col - 2] || lst[i][col + 2]) continue;

            lst[i][col] = true;
            bt(level + 1, i);
            lst[i][col] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m >> h;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= h; ++j) {
			lst[j][i * 2] = true;
		}
	}

	while (m--) {
		int x, y; cin >> x >> y;
		lst[x][y * 2 + 1] = true;
	}

	bt(0, 1);
    cout << (ans == 4 ? -1 : ans);
}