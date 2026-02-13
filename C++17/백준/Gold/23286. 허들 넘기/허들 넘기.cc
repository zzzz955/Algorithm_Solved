#include<iostream>
#include<algorithm>
using namespace std;

const int N = 301;
int n, m, t;
int arr[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			arr[i][j] = 2e9;
		}
	}

	while (m--) {
		int f, t, d; cin >> f >> t >> d;
		arr[f][t] = d;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (arr[i][k] == 2e9 || arr[k][j] == 2e9) continue;
				arr[i][j] = min( arr[i][j], max(arr[i][k], arr[k][j]) );
			}
		}
	}

	while (t--) {
		int f, t; cin >> f >> t;
		cout << (arr[f][t] == 2e9 ? -1 : arr[f][t]) << "\n";
	}
}