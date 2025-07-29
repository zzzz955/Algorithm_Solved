#include<iostream>
using namespace std;

void desc(string& s, int idx) {
	int phase = 0;
	for (int i = s.size() - 1; i > idx; --i) {
		s[i] = '0' + phase++;
	}
}

bool can(string& s) {
	if (s == "9876543210") return false;

	int len = s.size();
	while (len--) {
		if (len - 1 < 0) break;
		if (s[len] + 1 < s[len - 1]) {
			s[len]++;
			desc(s, len);
			return true;
		}
	}

	if (s[0] < '9') {
		s[0]++;
		int st = s.size() - 1;
		for (int i = 1; i < s.size(); ++i) {
			s[i] = '0' + --st;
		}
		return true;
	}

	int st = s.size();
	s = "";
	for (int i = st; i >= 0; --i) s += i + '0';
	return true;
}

int main() {
	int n; cin >> n;
	string s = "0";
	bool flag = true;
	while (--n) {
		//cout << s << "\n";
		if (!can(s)) {
			flag = false;
			break;
		}
	}
	cout << (flag ? s : "-1");
}