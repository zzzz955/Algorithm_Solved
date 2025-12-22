#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5;
struct Pos {
	int sx, ex, y, idx;
	bool operator<(const Pos& other) const {
		return sx < other.sx;
	}
};
Pos w[N];
int n, q;
int nodes[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		int sx, ex, y; cin >> sx >> ex >> y;
		w[i] = { sx, ex, y, i };
	}
	sort(w, w + n);

	for (int i = 0; i < n; ++i) nodes[i] = i;

	int mx = w[0].ex, cur = w[0].idx;
	for (int i = 1; i < n; ++i) {
		//cout << w[i].sx << " " << w[i].ex << " " << w[i].y << " " << w[i].idx << "\n";
		if (w[i].sx > mx) {
			mx = w[i].ex;
			cur = w[i].idx;
			continue;
		}
		nodes[w[i].idx] = cur;
		if (w[i].ex > mx) mx = w[i].ex;
	}

	//for (int i = 0; i < n; ++i) cout << nodes[i] << " ";
	//cout << "\n";

	while (q--) {
		int s, t; cin >> s >> t;
		cout << (nodes[--s] == nodes[--t] ? 1 : 0) << "\n";
	}
}