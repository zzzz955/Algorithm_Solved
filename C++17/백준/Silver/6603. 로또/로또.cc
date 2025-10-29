#include<iostream>
#include<vector>
using namespace std;

const int N = 14;
int k;
int s[N];
vector<int> c;

void print() {
	for (int i = 0; i < 6; ++i) {
		cout << s[c[i]];
		if (i != 5) cout << " ";
	}
	cout << "\n";
}

void bt(int select, int idx) {
	if (select > 6) return;
	if (idx == k) {
		if (select == 6) print();
		return;
	}

	c.push_back(idx);
	bt(select + 1, idx + 1);
	c.pop_back();

	bt(select, idx + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> k) {
		if (!k) break;
		for (int i = 0; i < k; ++i) cin >> s[i];
		bt(0, 0);
		cout << "\n";
	}
}