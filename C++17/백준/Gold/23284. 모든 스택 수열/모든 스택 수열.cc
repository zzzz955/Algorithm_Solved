#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> push;
vector<int> pop;

void print() {
	for (int i = 0; i < n; ++i) {
		cout << pop[i];
		if (i != n - 1) cout << " ";
	}
	cout << "\n";
}

void bt(int level) {
	if (level > n && push.empty()) {
		print();
		return;
	}

	if (!push.empty()) {
		int b = push.back();
		pop.push_back(b);
		push.pop_back();
		bt(level);
		push.push_back(b);
		pop.pop_back();
	}

	if (level <= n) {
		push.push_back(level);
		bt(level + 1);
		push.pop_back();
	}
}

int main() {

	ios::sync_with_stdio(0);
	cout.tie(0);

	cin >> n;
	bt(1);
}