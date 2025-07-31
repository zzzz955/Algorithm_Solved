#include<iostream>
#include<queue>
#include<map>
using namespace std;
using pii = pair<int, int>;

struct WB {
	int a, b;
};
int ma, mb, da, db;
map<pii, int> v;

int bfs() {
	queue<WB> q;
	q.push({ 0, 0 });
	v[{0, 0}] = 0;

	while (!q.empty()) {
		WB wb = q.front(); q.pop();
		int ca = wb.a, cb = wb.b;
		int nc = v[{ca, cb}] + 1;
		//cout << ca << " " << cb << "\n";
		if (ca == da && cb == db) return v[{ca, cb}];

		if (!v.count({ 0, cb })) {
			v[{ 0, cb }] = nc;
			q.push({ 0, cb });
		}

		if (!v.count({ ma, cb })) {
			v[{ ma, cb }] = nc;
			q.push({ ma, cb });
		}

		if (!v.count({ ca, 0 })) {
			v[{ ca, 0 }] = nc;
			q.push({ ca, 0 });
		}

		if (!v.count({ ca, mb })) {
			v[{ ca, mb }] = nc;
			q.push({ ca, mb });
		}

		int diff = ma - ca;
		if (cb > diff) {
			int nb = cb - diff;
			if (!v.count({ ma, nb })) {
				v[{ ma, nb }] = nc;
				q.push({ ma, nb });
			}
		}
		else {
			int na = ca + cb;
			if (!v.count({ na, 0 })) {
				v[{ na, 0 }] = nc;
				q.push({ na, 0 });
			}
		}

		diff = mb - cb;
		if (ca > diff) {
			int na = ca - diff;
			if (!v.count({ na, mb })) {
				v[{ na, mb }] = nc;
				q.push({ na, mb });
			}
		}
		else {
			int nb = ca + cb;
			if (!v.count({ 0, nb })) {
				v[{ 0, nb }] = nc;
				q.push({ 0, nb });
			}
		}
	}
	return -1;
}

int main() {
	cin >> ma >> mb >> da >> db;
	cout << bfs();
}