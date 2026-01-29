#include<iostream>
#include<vector>
using namespace std;

string s;
long long k;

int main() {
	cin >> s >> k;

	int n = s.size();
	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '6') s[i] = '1';
		if (s[i] == '7') s[i] = '2';
		if (s[i] == '1' || s[i] == '2')
			pos.push_back(i);
	}

	
	int m = pos.size();
	if (k > (1ll << m)) {
		cout << -1;
		return 0;
	}

	--k;
	for (int i = 0; i < m; ++i) {
		if (k & (1LL << (m - 1 - i))) {
			s[pos[i]] = (s[pos[i]] == '1') ? '6' : '7';
		}
	}

	cout << s;
}