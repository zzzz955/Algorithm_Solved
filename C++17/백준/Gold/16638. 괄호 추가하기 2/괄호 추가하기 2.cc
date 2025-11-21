#include<iostream>
#include<vector>
using namespace std;

int n;
string s;
char op[10];
int num[11];
vector<char> c_op;
vector<int> c_num;
int ans = -2e9;

void bt(int level, bool prev) {
	if (level >= n / 2) {
		vector<int> temp(1, c_num[0]);
		//cout << c_op.size() << " " << c_num.size() << "\n";
		//cout << c_num[0];
		//for (int i = 0; i < c_op.size(); ++i) cout << c_op[i] << c_num[i + 1];
		//cout << "\n";
		for (int i = 0; i < c_op.size(); ++i) {
			//cout << temp.back() << "\n";
			if (c_op[i] == '+') temp.push_back(c_num[i + 1]);
			else if (c_op[i] == '-') temp.push_back(-c_num[i + 1]);
			else temp.back() *= c_num[i + 1];
		}

		//cout << temp.back() << "\n";
		int sum = 0;
		for (int i : temp) sum += i;
		//cout << sum << "\n";
		ans = max(ans, sum);
		return;
	}

	int a = num[level + 1];
	char b = op[level];

	if (!prev) {
		int c = c_num.back(); c_num.pop_back();

		if (b == '+') c_num.push_back(c + a);
		else if (b == '-') c_num.push_back(c - a);
		else c_num.push_back(c * a);
		bt(level + 1, true);
		c_num.pop_back();
		if (b == '+') c_num.push_back(c);
		else if (b == '-') c_num.push_back(c);
		else c_num.push_back(c);
	}

	c_num.push_back(a);
	c_op.push_back(b);
	bt(level + 1, false);
	c_num.pop_back();
	c_op.pop_back();
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if (i % 2) op[i / 2] = s[i];
		else num[i / 2] = s[i] - '0';
	}

	c_num.push_back(num[0]);
	bt(0, false);
	cout << ans;
}