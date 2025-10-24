#include<iostream>
#include<vector>
#include<deque>
#include<unordered_set>
using namespace std;
using ll = long long;

ll ans;
string s;
bool flag = false;
vector<int> idx;
int n, m;;
unordered_set<char> dic = { 'A', 'E', 'I', 'O', 'U' };

bool search(const deque<char>& deq) {
	int u = 0, a = 0;
	for (char c : deq) {
		if (c == '_') return false;
		else if (dic.count(c)) a++;
	}
	return a == 0 || a == 3;
}

bool chk() {
	deque<char> deq;
	for (int i = 0; i < 3; ++i) deq.push_back(s[i]);
	if (search(deq)) {
		//cout << deq[0] << deq[1] << deq[2] << "\n";
		return false;
	}

	for (int i = 3; i < n; ++i) {
		deq.pop_front();
		deq.push_back(s[i]);
		if (search(deq)) {
			//cout << deq[0] << deq[1] << deq[2] << "\n";
			return false;
		}
	}
	return true;
}

void bt(int level, ll sum) {
	if (!chk()) return;
	if (level == m) {
		if (flag) {
			//cout << s << "\n";
			ans += sum;
		}
		return;
	}

	s[idx[level]] = 'L';
	if (flag) bt(level + 1, sum * 21);
	else {
		flag = true;
		bt(level + 1, sum);
		flag = false;
		bt(level + 1, sum * 20);
	}
	s[idx[level]] = '_';

	s[idx[level]] = 'A';
	bt(level + 1, sum * 5);
	s[idx[level]] = '_';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = s.size();
	if (n < 3) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (s[i] == '_') idx.push_back(i);
		if (s[i] == 'L') flag = true;
	}

	m = idx.size();
	bt(0, 1);
	cout << ans;
}