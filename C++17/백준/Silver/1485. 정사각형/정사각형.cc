#include<iostream>
#include<array>
#include<map>
#include<cmath>
using namespace std;
using pii = pair<int, int>;

int t;

int get_dist(const pii& a, const pii& b) {
	int ax = a.first, ay = a.second;
	int bx = b.first, by = b.second;
	return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

int main() {
	cin >> t;
	while (t--) {
		array<pii, 4> coords;
		for (int i = 0; i < 4; ++i) {
			int x, y; cin >> x >> y;
			coords[i] = { x, y };
		}
		
		map<int, int> w;
		for (int i = 0; i < 4; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				pii a = coords[i], b = coords[j];
				int dist = get_dist(a, b);
				w[dist]++;
			}
		}
		
		if (w.size() == 2 && w.begin()->second == 4 && w.rbegin()->second == 2) cout << 1;
		else cout << 0;
		cout << "\n";
	}
}