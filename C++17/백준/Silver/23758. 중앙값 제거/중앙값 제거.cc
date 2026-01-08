#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2e6;
int arr[N];
int n;
priority_queue<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		if (i < (n + 1) >> 1) a.push(arr[i]);
	}

	int ans = 0;
	while (!a.empty()) {
		int cur = a.top(); a.pop();
		if (cur == 1) break;
		
		while (cur > 1) {
			++ans;
			cur >>= 1;
		}
	}
	cout << ++ans;
}