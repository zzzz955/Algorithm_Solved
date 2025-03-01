#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500000;
int n, m;
int nodes[N];

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return true;
	nodes[B] = A;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) nodes[i] = i;

	for (int i = 1; i <= m; ++i) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		if (Union(a, b)) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}