#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e6 + 1;
int x;
int v[N];
int path[N];
queue<int> q;

void insert(int cx, int nx) {
	if (1 <= nx && nx < N && !v[nx]) {
		v[nx] = v[cx] + 1;
		path[nx] = cx;
		q.push(nx);
	}
}

void bfs() {
	q.push(x);

	while (!q.empty()) {
		int cx = q.front(); q.pop();
		if (cx == 1) break;

		if (cx % 3 == 0) insert(cx, cx / 3);
		if (cx % 2 == 0) insert(cx, cx / 2);
		insert(cx, cx - 1);
	}
	
	int cur = 1;
	cout << v[1] << "\n";

	vector<int> rev;
	while (cur) {
		rev.push_back(cur);
		cur = path[cur];
	}
	reverse(rev.begin(), rev.end());

	for (int i : rev) cout << i << " ";
}

int main() {
	cin >> x;
	bfs();
}