#include<iostream>
#include<queue>
using namespace std;

const int N = 1e5;
int arr[N];
int n, x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int l = 1, r = n, ans = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < mid; ++i) pq.push(0);

		bool flag = true;
		for (int i = 0; i < n; ++i) {
			int t = arr[i];
			int c = pq.top(); pq.pop();

			if (c + t > x) {
				flag = false;
				break;
			}
			
			pq.push(c + t);
		}

		if (flag) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}