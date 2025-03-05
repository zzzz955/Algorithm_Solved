#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int a, b, c, total;
bool v[1501][1501];
struct S {
	int a, b;
};

bool bfs() {
	queue<S> q;
	q.push({ a, b });
	v[a][b] = true;

	while (!q.empty()) {
		S s = q.front(); q.pop();
		int a = s.a, b = s.b, c = total - s.a - s.b;
		if (a == b && b == c) return true;

		int abc[3] = { a, b, c };
		for (int i = 0; i < 2; ++i) {
			int n1 = abc[i];
			for (int j = i + 1; j < 3; ++j) {
				int n2 = abc[j];
				if (n1 != n2) {
					if (n1 > n2) swap(n1, n2);
					n2 -= n1;
					n1 *= 2;
					//cout << n1 << " " << n2 << " " << total - n1 - n2 << "\n";
					if (v[n1][n2]) continue;
					v[n1][n2] = true;
					q.push({ n1, n2 });
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> a >> b >> c;
	total = a + b + c;
	cout << bfs();
}