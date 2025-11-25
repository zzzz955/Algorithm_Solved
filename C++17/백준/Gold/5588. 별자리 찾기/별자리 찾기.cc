#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
using ll = long long;

const ll X = 1e7;
int n, m, tx, ty;
unordered_set<ll> stars;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> tx >> ty;
	vector<ll> pos;
	for (int i = 0; i < m - 1; ++i) {
		int x, y; cin >> x >> y;
		pos.push_back(X * x + y);
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		stars.insert(X * x + y);
	}

	for (ll star : stars) {
		int x = star / X, y = star % X;
		int diff_x = tx - x, diff_y = ty - y;
		bool flag = true;
		//cout << "===========================\n";
		//cout << x << " " << y << " " << diff_x << " " << diff_y << "\n";

		for (ll p : pos) {
			int cx = p / X, cy = p % X;
			int nx = cx - diff_x, ny = cy - diff_y;
			//cout << cx << " " << cy << " " << nx << " " << ny << "\n";
			if (nx < 0 || ny < 0 || !stars.count(X * nx + ny)) {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << -diff_x << " " << -diff_y;
			return 0;
		}
	}
}