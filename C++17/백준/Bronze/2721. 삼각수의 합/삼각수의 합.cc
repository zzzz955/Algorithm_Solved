#include<iostream>
using namespace std;

const int N = 301;
int t[N + 1];
int w[N + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= N; ++i) t[i] = t[i - 1] + i;
	for (int i = 1; i < N; ++i) {
		w[i] = w[i - 1] + i * t[i + 1];
	}

	int q; cin >> q;
	while (q--) {
		int i; cin >> i;
		cout << w[i] << "\n";
	}
}