#include<iostream>
using namespace std;

int n;
int st[] = { 2, 3, 5, 7 };
int odd[] = { 1, 3, 7, 9 };

bool is_prime(int val) {
	int i = 3;
	while (i * i <= val) {
		if (val % i == 0) return false;
		i += 2;
	}
	return true;
}

void dfs(int level, int val) {
	if (!is_prime(val)) return;

	if (level == n) {
		cout << val << "\n";
		return;
	}

	for (int i : odd) dfs(level + 1, val * 10 + i);
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	cin >> n;
	for (int i : st) dfs(1, i);
}