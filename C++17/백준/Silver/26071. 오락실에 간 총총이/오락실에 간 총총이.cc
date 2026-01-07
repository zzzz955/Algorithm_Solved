#include<iostream>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int minR = n, maxR = -1, minC = n, maxC = -1;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;

		for (int j = 0; j < n; ++j) {
			if (s[j] == 'G') {
				minR = min(minR, i);
				maxR = max(maxR, i);
				minC = min(minC, j);
				maxC = max(maxC, j);
			}
		}
	}

	int V = (minR == maxR) ? 0 : min(maxR, (n - 1) - minR);
	int H = (minC == maxC) ? 0 : min(maxC, (n - 1) - minC);
	//cout << V << " " << H << "\n";
	cout << (V + H);
}