#include<iostream>
using namespace std;

string a, b, c;

int main() {
	cin >> a;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '(') b += a[i];
		else if (a[i] == ')') {
			while (b.back() != '(') {
				c += b.back();
				b.pop_back();
			}
			b.pop_back();
		}
		else if ('A' <= a[i] && a[i] <= 'Z') c += a[i];
		else if (a[i] == '+' || a[i] == '-') {
			while (!b.empty() && b.back() != '(') {
				c += b.back();
				b.pop_back();
			}
			b += a[i];
		}
		else {
			while (!b.empty() && b.back() != '(' && b.back() != '+' && b.back() != '-') {
				c += b.back();
				b.pop_back();
			}
			b += a[i];
		}
		//cout << a[i] << " " << b << " " << c << "\n";
	}
	while (!b.empty()) {
		c += b.back();
		b.pop_back();
	}
	cout << c;
}