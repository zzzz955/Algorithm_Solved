#include<iostream>
#include<queue>
using namespace std;

const int N = 1e6 + 1;
int n, k;
int v[N];
struct Pos {
	int x, t;
};

void up(int x, int t, queue<Pos>& q) {
	if (x > n || v[x] <= t || t > k) return;
	v[x] = t;
	q.push({ x, t });
}

string bfs() {
	queue<Pos> q;
	q.push({ 0, 0 });
	v[0] = 0;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int x = pos.x, t = pos.t;

		if (x == n) return "minigimbob";

		up(x + 1, t + 1, q);
		up(x + x / 2, t + 1, q);
	}
	return "water";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i <= n; ++i) v[i] = 2e9;
	cout << bfs();
}