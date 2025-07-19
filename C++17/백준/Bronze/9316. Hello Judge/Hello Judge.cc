#include<iostream>
using namespace std;

const string S = "Hello World, Judge ";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cout << S << i << "!\n";
}