#include<iostream>
#include<algorithm>
using namespace std;

int n[4];

int main() {
	for (int i = 0; i < 4; ++i) cin >> n[i];
	sort(n, n + 4);
	cout << n[0] * n[2];
}