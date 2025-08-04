#include<iostream>
#include<queue>
using namespace std;

const int N = 1e5;
int n, s;
int lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		s += lst[i];
	}

	if (s % 3) {
		cout << "NO";
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) cnt += lst[i] / 2;
	cout << (cnt >= s / 3 ? "YES" : "NO");
}