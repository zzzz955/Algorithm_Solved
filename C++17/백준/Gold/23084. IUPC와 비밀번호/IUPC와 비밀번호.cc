#include<iostream>
#include<cstring>
#include<deque>
#include<algorithm>
using namespace std;

string s, t;
int n, sl, tl;
int sc['z' + 1];
int tc['z' + 1];

bool chk() {
	int diff = 0;
	for (int i = 'a'; i <= 'z'; ++i) {
		diff += abs(sc[i] - tc[i]);
	}
	return diff <= 2 ? true : false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> n;
	sl = s.size();
	for (char ch : s) sc[ch]++;
	while (n--) {
		cin >> t;
		tl = t.size();
		if (tl < sl) {
			cout << "NO\n";
			continue;
		}
		else if (tl == sl) {
			string temp1 = s;
			string temp2 = t;
			sort(temp1.begin(), temp1.end());
			sort(temp2.begin(), temp2.end());
			if (temp1 == temp2) {
				cout << "NO\n";
				continue;
			}
		}
		memset(tc, 0, sizeof(tc));
		deque<char> deq;
		for (int i = 0; i < sl; ++i) {
			deq.push_back(t[i]);
			tc[t[i]]++;
		}
		if (chk()) {
			cout << "YES\n";
			continue;
		}

		bool flag = false;
		for (int i = sl; i < tl; ++i) {
			tc[deq.front()]--;
			deq.pop_front();
			tc[t[i]]++;
			deq.push_back(t[i]);
			
			if (chk()) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}