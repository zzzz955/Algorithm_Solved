#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 1;
bool p[N];
int pre[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 2; i * i < N; ++i) {
		if (p[i]) continue;
		//cout << i << " " << p[i] << "\n";
		for (int j = i * i; j < N; j += i) p[j] = true;
	}

	for (int i = 2; i < N; ++i) pre[i] = pre[i - 1] + (p[i] ? 0 : 1);

	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		int cnt = pre[b] - pre[a - 1];
		//cout << cnt << "\n";

		if (cnt % 2) {
			int l = a, r = b;

			while (l <= r) {
				int mid = (l + r) / 2;
				int sum = pre[mid] - pre[a - 1];

				if (sum == (cnt + 1) / 2 && !p[mid]) {
					cout << mid << "\n";
					break;
				}
				else if (sum < (cnt + 1) / 2) l = mid + 1;
				else r = mid - 1;
			}
		}
		else cout << -1 << "\n";
	}
}