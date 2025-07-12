#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 50;
int n, m;

int get_best(priority_queue<int>& pq) {
	int res = 0;
	while (!pq.empty()) {
		int cnt = m, best = pq.top();
		while (!pq.empty() && cnt--) pq.pop();
		res += best;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	priority_queue<int> P, M;
	int mv = 0;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		if (a > 0) P.push(a * 2);
		else M.push(a * -2);
		mv = max(mv, abs(a));
	}

	int ans = 0;
	ans += get_best(P);
	ans += get_best(M);
	cout << ans - mv;
}