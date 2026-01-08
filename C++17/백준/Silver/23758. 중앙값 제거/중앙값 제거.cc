#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2e6;
int arr[N];
int n;
priority_queue<int> a;
priority_queue<int, vector<int>, greater<int>> b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		if (i < (n + 1) / 2) a.push(arr[i]);
		else b.push(arr[i]);
	}

	int ans = 0;
	while (1) {
		int cur = a.top(); a.pop();
		if (cur == 1) break;
		
		int next = cur;
		for (; next > 1; next /= 2) ++ans;

		a.push(next);
		if (a.size() > b.size() + 1) {
			b.push(a.top());
			a.pop();
		}
	}
	cout << ++ans;
}