#include<iostream>
using namespace std;

const int N = 1e4;
const int INF = 2e9;
struct Pos {
	int x, y, z;
};
Pos arr[N];
int n;
int best1[N], best2[N];

int get_dist(const Pos& left, const Pos& right) {
	return abs(left.x - right.x) + abs(left.y - right.y) + abs(left.z - right.z);
}

void update(int d, int& b1, int& b2) {
	if (d < b1) b2 = b1, b1 = d;
	else if (d < b2) b2 = d;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y, z; cin >> x >> y >> z;
		arr[i] = { x, y, z };
		best1[i] = INF;
		best2[i] = INF;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			int d = get_dist(arr[i], arr[j]);
			update(d, best1[i], best2[i]);
			update(d, best1[j], best2[j]);
		}
	}

	int ans = INF;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, best1[i] + best2[i]);
	}
	
	cout << ans;
}