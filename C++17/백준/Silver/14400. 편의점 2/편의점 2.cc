#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5;
int xs[N], ys[N];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		xs[i] = x, ys[i] = y;
	}

	sort(xs, xs + n);
	sort(ys, ys + n);

	long long sum = 0;
	int mx = xs[n / 2], my = ys[n / 2];
	for (int i = 0; i < n; ++i) sum += abs(mx - xs[i]) + abs(my - ys[i]);
	cout << sum;
}