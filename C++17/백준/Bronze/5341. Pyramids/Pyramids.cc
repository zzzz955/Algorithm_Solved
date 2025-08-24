#include<iostream>
using namespace std;

int n;
int lst[50001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lst[1] = 1;
	for (int i = 2; i <= 50000; ++i) lst[i] = lst[i - 1] + i;
	//cout << lst[50000];
	while (cin >> n) {
		if (!n) break;
		cout << lst[n] << "\n";
	}
}