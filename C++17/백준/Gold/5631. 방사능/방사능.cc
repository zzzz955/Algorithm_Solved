#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 200000;
int n;
struct Pos {
	int x, y;
};
Pos lst[N];
double adists[N], bdists[N];

double getDist(int x, int y, int tx, int ty) {
	return pow(pow(x - tx, 2) + pow(y - ty, 2), 0.5f);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int c = 0;
	while (++c) {
		cin >> n;
		if (!n) break;
		cout << "Case " << c << ":\n";

		for (int i = 0; i < n; ++i) {
			int x, y; cin >> x >> y;
			lst[i] = { x, y };
		}

		int ax, ay, bx, by, q; cin >> ax >> ay >> bx >> by >> q;
		for (int i = 0; i < n; ++i) {
			adists[i] = getDist(lst[i].x, lst[i].y, ax, ay);
			bdists[i] = getDist(lst[i].x, lst[i].y, bx, by);
		}
		
		sort(adists, adists + n);
		sort(bdists, bdists + n);
		while (q--) {
			int r1, r2; cin >> r1 >> r2;
			int ac = upper_bound(adists, adists + n, r1) - adists;
			int bc = upper_bound(bdists, bdists + n, r2) - bdists;
			int result = ac + bc >= n ? 0 : n - (ac + bc);
			cout << result << "\n";
		}
	}
}