#include<iostream>
using namespace std;

int lst[6][3];
bool v[6][6];
bool flag;

void bt(int level) {
	if (flag) return;
	//cout << "running...\n";
	if (level == 15) {
		flag = true;
		return;
	}

	int x = -1, y = -1;
	for (int i = 0; i < 5 && x == -1; ++i) {
		for (int j = i + 1; j < 6; ++j) {
			if (v[i][j]) continue;
			x = i, y = j;
			break;
		}
	}

	v[x][y] = true;
	if (lst[x][1] && lst[y][1]) {
		lst[x][1]--;
		lst[y][1]--;
		bt(level + 1);
		lst[x][1]++;
		lst[y][1]++;
	}

	if (lst[x][0] && lst[y][2]) {
		lst[x][0]--;
		lst[y][2]--;
		bt(level + 1);
		lst[x][0]++;
		lst[y][2]++;
	}

	if (lst[x][2] && lst[y][0]) {
		lst[x][2]--;
		lst[y][0]--;
		bt(level + 1);
		lst[x][2]++;
		lst[y][0]++;
	}
	v[x][y] = false;
}

bool pre_chk() {
	for (int i = 0; i < 6; ++i) {
		int sum = 0;
		for (int j = 0; j < 3; ++j) {
			sum += lst[i][j];
		}
		if (sum != 5) return false;
	}
	return true;
}

int main() {
	for (int t = 0; t < 4; ++t) {
		flag = false;
		for (int i = 0; i < 6; ++i) {
			v[i][i] = true;
			for (int j = 0; j < 3; ++j) {
				cin >> lst[i][j];
			}
		}
		if (!pre_chk()) {
			cout << 0 << " ";
			continue;
		}
		bt(0);
		cout << flag << " ";
	}
}