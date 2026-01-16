#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Pos {
	int x, y;
	bool operator<(const Pos& other) const {
		if (y == other.y) return x > other.x;
		return y > other.y;
	}
};
const int N = 1e6;
Pos arr[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		arr[i] = { x, y };
	}
	sort(arr, arr + n);
	
	long long sum = 1ll * arr[0].x * arr[0].y;
	vector<int> xs(1, arr[0].x);

	for (int i = 1; i < n; ++i) {
		auto [x, y] = arr[i];
		int y_diff = arr[i - 1].y - arr[i].y;
		while (!xs.empty() && xs.back() <= x) {
			sum += 1ll * (x - xs.back()) * y;
			xs.pop_back();
		}
		if (xs.empty()) xs.push_back(x);
		//cout << x << " " << y << " " << sum << "\n";
	}
	
	cout << sum;
}