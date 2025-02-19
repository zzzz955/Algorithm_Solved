#include<iostream>
#include<deque>
using namespace std;

int n, l;
struct VI {
	int val, idx;
};
deque<VI> deq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		while (!deq.empty() && deq.back().val >= a) deq.pop_back();
		deq.push_back({ a, i });

		while (!deq.empty() && deq.front().idx <= i - l) deq.pop_front();

		cout << deq.front().val << " ";
	}
}