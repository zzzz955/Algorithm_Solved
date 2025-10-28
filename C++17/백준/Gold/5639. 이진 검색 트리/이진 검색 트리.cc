#include<iostream>
#include<vector>
using namespace std;

int n, idx;
vector<int> a;

void build(int lo, int hi) {
	if (idx >= n) return;
	int v = a[idx];
	if (v <= lo || v >= hi) return;
	++idx;
	build(lo, v);
	build(v, hi);
	cout << v << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x;
	while (cin >> x) a.push_back(x);
	n = a.size();

	build(0, 1e6);
}