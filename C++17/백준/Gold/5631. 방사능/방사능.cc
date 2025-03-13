#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
struct Pos {
	int x, y;
};
Pos lst[200000];

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
		vector<double> adists, bdists;
		for (int i = 0; i < n; ++i) {
			double adist = getDist(lst[i].x, lst[i].y, ax, ay);
			double bdist = getDist(lst[i].x, lst[i].y, bx, by);
			//cout << adist << " " << bdist << "\n";
			adists.push_back(adist);
			bdists.push_back(bdist);
		}
		
		sort(adists.begin(), adists.end());
		sort(bdists.begin(), bdists.end());
		while (q--) {
			int r1, r2; cin >> r1 >> r2;
			int ac = upper_bound(adists.begin(), adists.end(), r1) - adists.begin();
			int bc = upper_bound(bdists.begin(), bdists.end(), r2) - bdists.begin();
			int result = ac + bc >= n ? 0 : n - (ac + bc);
			cout << result << "\n";
		}
	}
}