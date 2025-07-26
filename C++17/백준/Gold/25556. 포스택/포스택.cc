#include<iostream>
using namespace std;
int n, a, i, back[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (cin >> a) {
		bool flag = false;
		for (i = 0; i < 4; ++i) {
			if (back[i] < a) {
				flag = true;
				back[i] = a;
				break;
			}
		}
		if (!flag) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}