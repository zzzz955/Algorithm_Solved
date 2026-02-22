#include<iostream>
using namespace std;

int main() {
	int sum = 1500;
	for (int i = 0; i < 4; ++i) {
		int d; cin >> d;
		sum -= d;
	}
	cout << (sum < 0 ? "No" : "Yes");
}