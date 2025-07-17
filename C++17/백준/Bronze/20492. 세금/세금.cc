#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double n; cin >> n;
	double z = 0.22f;
	int a1 = round(n * (1 - z));
	int a2 = round(n * (1 - z * 0.2f));
	cout << a1 << " " << a2;
}