#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1e4;
int n, m;
int arr[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n, greater<int>());

	priority_queue<int, vector<int>, greater<int>> pq;
	while (m--) pq.push(0);

	for (int i = 0; i < n; ++i) {
		int d = arr[i];
		int c = pq.top(); pq.pop();
		pq.push(c + d);
	}

	while (1) {
		int c = pq.top();  pq.pop();
		if (pq.empty()) {
			cout << c;
			break;
		}
	}
}