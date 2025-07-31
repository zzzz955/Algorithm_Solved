#include<iostream>
#include<queue>
using namespace std;

struct WB {
	int a, b, c;
};
int ma, mb, da, db;
bool v[1001][1001];

int bfs() {
	queue<WB> q;
	q.push({0, 0, 0});
	v[0][0] = true;

	while (!q.empty()) {
		WB wb = q.front(); q.pop();
		int ca = wb.a, cb = wb.b, cc = wb.c;
		//cout << ca << " " << cb << "\n";
		if (ca == da && cb == db) return cc;

		if (!v[ma][cb]) {
			v[ma][cb] = true;
			q.push({ ma, cb, cc + 1 });
		}

		if (!v[ca][mb]) {
			v[ca][mb] = true;
			q.push({ ca, mb, cc + 1 });
		}

		if (!v[0][cb]) {
			v[0][cb] = true;
			q.push({ 0, cb, cc + 1 });
		}

		if (!v[ca][0]) {
			v[ca][0] = true;
			q.push({ ca, 0, cc + 1 });
		}

		int diff = ma - ca;
		if (cb > diff) {
			if (!v[ma][cb - diff]) {
				v[ma][cb - diff] = true;
				q.push({ ma, cb - diff, cc + 1 });
			}
		}
		else {
			if (!v[ca + cb][0]) {
				v[ca + cb][0] = true;
				q.push({ ca + cb, 0, cc + 1 });
			}
		}

		diff = mb - cb;
		if (ca > diff) {
			if (!v[ca - diff][mb]) {
				v[ca - diff][mb] = true;
				q.push({ ca - diff, mb, cc + 1 });
			}
		}
		else {
			if (!v[0][ca + cb]) {
				v[0][ca + cb] = true;
				q.push({ 0, ca + cb, cc + 1 });
			}
		}
	}
	return -1;
}

int main() {
	cin >> ma >> mb >> da >> db;
	cout << bfs();
}