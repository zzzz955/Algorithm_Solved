#include<iostream>
#include<queue>
using namespace std;

int a, k;
int v[1000001];

int bfs() {
	queue<int> q;
	q.push(a);
	v[a] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == k) return v[cur];

		if (cur + 1 <= k && !v[cur + 1]) {
			v[cur + 1] = v[cur] + 1;
			q.push(cur + 1);
		}

		if (cur * 2 <= k && !v[cur * 2]) {
			v[cur * 2] = v[cur] + 1;
			q.push(cur * 2);
		}
	}
	return -1;
}

int main() {
	cin >> a >> k;
	cout << bfs();
}