#include<iostream>
#include<queue>
using namespace std;

const int N = 3e5;
int n, k;
int lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	priority_queue<int> pq;
	for (int i = 1; i < n; ++i) {
		pq.push(lst[i] - lst[i - 1]);
	}

	while (--k) pq.pop();
	long long ans = 0;
	while (!pq.empty()) {
		ans += pq.top(); pq.pop();
	}

	cout << ans;
}