#include<iostream>
using namespace std;

int n;
string ans;
bool flag;

void bt(int level) {
	if (flag) return;
	if (level == n) {
		flag = true;
		cout << ans;
		return;
	}
	//cout << ans << "\n";

	for (char c = '1'; c <= '3'; ++c) {
		ans += c;
		int len = ans.size();
		bool can = true;
		for (int i = 1; i <= len / 2; ++i) {
			string f = ans.substr(len - (i * 2), i);
			string b = ans.substr(len - i, i);
			//cout << ans << " " << f << " " << b << "\n";
			
			if (f == b) {
				can = false;
				break;
			}
		}
		if (can) bt(level + 1);
		ans.pop_back();
	}
}

int main() {
	cin >> n;
	bt(0);
}