#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> stack[4];
int back[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int a; cin >> a;
		
		bool flag = false;
		for (int i = 0; i < 4; ++i) {
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