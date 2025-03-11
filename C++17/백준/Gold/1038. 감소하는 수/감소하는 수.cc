#include<iostream>
using namespace std;

int main() {
	int n;  cin >> n;
	if (n <= 9) {
		cout << n;
		return 0;
	}
	else if (n > 1022) {
		cout << -1;
		return 0;
	}

	int cur = 9;
	string s = "10";
	while (++cur < n) {
		int idx = s.size();
		while (idx--) {
			if (s[idx] == '9') {
				int l = s.size() + 1;
				s.clear();
				for (int i = l - 1; i >= 0; --i) s += i + '0';
				break;
			}
			else if (idx == 0 || s[idx] < s[idx - 1] - 1) {
				s[idx]++;
				for (int i = idx + 1; i < s.size(); ++i) {
					s[i] = s.size() - i + '0' - 1;
				}
				break;
			}
		}
	}
	cout << s;
}