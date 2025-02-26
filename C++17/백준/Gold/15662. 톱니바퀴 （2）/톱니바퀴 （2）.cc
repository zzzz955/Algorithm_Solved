#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int t, k, flag;
deque<char> deq[1001];

void turn_right(int idx) {
	char ch = deq[idx].back();
	deq[idx].pop_back();
	deq[idx].push_front(ch);
	flag ^= 1;
}

void turn_left(int idx) {
	char ch = deq[idx].front();
	deq[idx].pop_front();
	deq[idx].push_back(ch);
	flag ^= 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 1; i <= t; ++i) {
		string s; cin >> s;
		for (int j = 0; j < 8; ++j) {
			deq[i].push_back(s[j]);
		}
	}

	cin >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		vector<int> left, right;

		int L = a;
		while (--L > 0) {
			if (deq[L][2] != deq[L + 1][6]) left.push_back(L);
			else break;
		}

		int R = a;
		while (++R <= t) {
			if (deq[R - 1][2] != deq[R][6]) right.push_back(R);
			else break;
		}

		flag = 0;
		if (b == -1) {
			turn_left(a);
			for (int i : left) {
				if (flag) turn_right(i);
				else turn_left(i);
			}

			flag = 1;
			for (int i : right) {
				if (flag) turn_right(i);
				else turn_left(i);
			}
		}
		else if (b == 1) {
			turn_right(a);
			for (int i : left) {
				if (flag) turn_left(i);
				else turn_right(i);
			}

			flag = 1;
			for (int i : right) {
				if (flag) turn_left(i);
				else turn_right(i);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= t; ++i) {
		if (deq[i][0] == '1') ans++;
	}
	cout << ans;
}