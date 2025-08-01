#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int n, s;
int lst[50];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	cin >> s;
	
	int idx = 0;
	while (s) {
		priority_queue<pii> pq;
		for (int i = idx; i <= min(n - 1, idx + s); ++i) pq.push({ lst[i], i });
		if (pq.empty()) break;
		pii best = pq.top();
		int val = best.first;
		int tar = best.second;
		//cout << s << " " << tar << " " << val << "\n";
		for (int i = tar; i > idx; --i) swap(lst[i], lst[i - 1]);
		s -= tar - idx;
		idx++;
		//for (int i = 0; i < n; ++i) cout << lst[i] << " ";
		//cout << "\n";
	}
	for (int i = 0; i < n; ++i) cout << lst[i] << " ";
}