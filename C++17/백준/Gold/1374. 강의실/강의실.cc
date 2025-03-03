#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, ans;
struct T {
	int st, et;
	bool operator<(const T& other) const {
		return et > other.et;
	}
};
T lst[100000];
priority_queue<T> pq;

bool cmp(const T& left, const T& right){
	return left.st < right.st;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, c; cin >> a >> b >> c;
		lst[i] = { b, c };
	}

	sort(lst, lst + n, cmp);
	for (int i = 0; i < n; ++i) {
		int time = lst[i].st;
		pq.push(lst[i]);
		while (!pq.empty() && pq.top().et <= time) pq.pop();
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
}