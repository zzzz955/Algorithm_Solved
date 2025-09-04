#include<iostream>
using namespace std;

int n, m, ans;
int lst[5][5];
bool v[5][5];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void print() {
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

void bt(int x, int sum) {
	ans = max(ans, sum);
	if (x == n) return;
	//print();

	for (int i = x; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j]) continue;
			for (int k = 0; k < 4; ++k) {
				int nx1 = i + dx[k], ny1 = j + dy[k];
				int nx2 = i + dx[k  + 1 == 4 ? 0 : k + 1], ny2 = j + dy[k + 1 == 4 ? 0 : k + 1];
				if (nx1 < 0 || n <= nx1 || ny1 < 0 || m <= ny1) continue;
				if (nx2 < 0 || n <= nx2 || ny2 < 0 || m <= ny2) continue;
				if (v[nx1][ny1] || v[nx2][ny2]) continue;
				//cout << i << " " << j << " " << nx1 << " " << ny1 << " " << nx2 << " " << ny2 << "\n";
				v[i][j] = true;
				v[nx1][ny1] = true;
				v[nx2][ny2] = true;
				bt(i, sum + lst[i][j] * 2 + lst[nx1][ny1] + lst[nx2][ny2]);
				v[i][j] = false;
				v[nx1][ny1] = false;
				v[nx2][ny2] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> lst[i][j];
		}
	}

	bt(0, 0);
	cout << ans;
}