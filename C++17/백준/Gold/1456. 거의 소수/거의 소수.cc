#include<iostream>
using namespace std;
using ll = long long;

const int N = 1e7 + 1;
bool chk[N];
ll a, b;

int main() {
	chk[1] = true;
	for (int i = 2; i * i < N; ++i) {
		if (chk[i]) continue;
		for (int j = i * i; j < N; j += i) {
			chk[j] = true;
		}
	}

	cin >> a >> b;
	int ans = 0;
	for (ll i = 2; i * i <= b; ++i) {
		if (chk[i]) continue;

		for (ll j = i * i; j <= b; j *= i) {
			if (j < a) continue;
			ans++;
			if (j > b / i) break;
			//cout << i << " " << j << "\n";
		}
	}
	cout << ans;
}