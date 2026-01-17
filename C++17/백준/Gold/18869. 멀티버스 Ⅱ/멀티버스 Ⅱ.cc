#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int M = 100;
const int N = 1e4;
int m, n;
int arr[M][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	
	for (int i = 0; i < m; ++i) {
		vector<int> cs;

		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			cs.push_back(arr[i][j]);
		}

		sort(cs.begin(), cs.end());
		cs.erase(unique(cs.begin(), cs.end()), cs.end());

		for (int j = 0; j < n; ++j) {
			arr[i][j] = lower_bound(cs.begin(), cs.end(), arr[i][j]) - cs.begin();
		}
	}

	int sum = 0;
	for (int i = 0; i < m - 1; ++i) {
		for (int j = i + 1; j < m; ++j) {
			bool flag = true;

			for (int k = 0; k < n; ++k) {
				if (arr[i][k] != arr[j][k]) {
					flag = false;
					break;
				}
			}

			if (flag) ++sum;
		}
	}
	cout << sum;
}