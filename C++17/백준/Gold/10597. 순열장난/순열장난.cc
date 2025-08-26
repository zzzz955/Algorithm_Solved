#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string s;
int n, m;
bool flag;
bool v[51];
vector<int> path;

void bt(int idx) {
	if (flag) return;
	if (idx >= n) {
		flag = true;
		for (int i : path) cout << i << " ";
		return;
	}
	if (s[idx] == '0') return;
	
	int one = s[idx] - '0';
	if (!v[one] && one <= m) {
		v[one] = true;
		path.push_back(one);
		bt(idx + 1);
		path.pop_back();
		v[one] = false;
	}

	if (idx == n - 1) return;
	int two = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
	if (!v[two] && two <= m) {
		v[two] = true;
		path.push_back(two);
		bt(idx + 2);
		path.pop_back();
		v[two] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	n = s.size();
	m = s.size() >= 10 ? (s.size() - 9) / 2 + 9 : s.size();
	bt(0);
}