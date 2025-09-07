#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;

int n, m;
string s, c;
set<string> dic;
unordered_set<string> sv;
bool v[20];

void bt(int level) {
	if (level == m) {
		dic.insert(c);
		return;
	}
	if (sv.count(c)) return;
	sv.insert(c);

	for (int i = 0; i < m; ++i) {
		if (v[i]) continue;
		v[i] = true;
		c += s[i];
		bt(level + 1);
		c.pop_back();
		v[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> s;
		sort(s.begin(), s.end());
		m = s.size();
		dic.clear();
		sv.clear();
		bt(0);
		//cout << dic.size();
		for (const string& s : dic) cout << s << '\n';
	}
}