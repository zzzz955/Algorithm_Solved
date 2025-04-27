#include<iostream>
using namespace std;

int main() {
	while (1) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (s == "#") break;
		cout << s;
		if (a > 17 || b >= 80) cout << " Senior\n";
		else cout << " Junior\n";
	}
}