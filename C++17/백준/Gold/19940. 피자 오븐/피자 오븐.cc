#include<iostream>
#include<queue>
using namespace std;

const int N = 65;
int t, n;
struct T {
	int ah, at, mt, ao, mo, cur;
};
T ts[N];
bool v[N];

void bfs() {
	queue<T> q;
	q.push({ 0, 0, 0, 0, 0, 0 });

	while (!q.empty()) {
		T t = q.front(); q.pop();
		int ah = t.ah, at = t.at, mt = t.mt, ao = t.ao, mo = t.mo, cur = t.cur;

		if (0 <= cur && cur <= 60 && !v[cur]) {
			v[cur] = true;
			ts[cur] = t;
			q.push({ ah, at, mt, ao, mo + 1, cur - 1 });
			q.push({ ah, at, mt, ao + 1, mo, cur + 1 });
			q.push({ ah, at, mt + 1, ao, mo, cur - 10 });
			q.push({ ah, at + 1, mt, ao, mo, cur + 10 });
			q.push({ ah + 1, at, mt, ao, mo, cur + 60 });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bfs();
	cin >> t;
	while (t--) {
		cin >> n;
		int div = n / 60;
		n %= 60;
		cout << ts[n].ah + div << " " << ts[n].at << " " << ts[n].mt << " " << ts[n].ao << " " << ts[n].mo << "\n";
	}
}

