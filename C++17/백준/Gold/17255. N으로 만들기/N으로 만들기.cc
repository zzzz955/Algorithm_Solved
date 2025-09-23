#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int n, ans;
string s;
unordered_set<string> dic;
unordered_set<string> paths;
bool v[10];

void bt(int level, string cur, string path) {
	if (level == n) {
		if (!paths.count(path)) {
			paths.insert(path);
			ans++;
		}
		return;
	}

	for (int i = 0; i <= 9; ++i) {
		if (v[i]) {
			string back = cur + to_string(i);
			if (dic.count(back)) {
				bt(level + 1, back, path + back);
			}

			string front = to_string(i) + cur;
			if (dic.count(front)) {
				bt(level + 1, front, path + front);
			}
		}
	}
}

int main() {
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; ++i) {
		v[s[i - 1] - '0'] = true;
		for (int j = 0; j <= n - i; ++j) {
			string temp = s.substr(j, i);
			dic.insert(temp);
		}
	}

	for (int i = 0; i <= 9; ++i) {
		string first = to_string(i);
		if (v[i]) bt(1, first, first);
	}
	cout << ans;
}