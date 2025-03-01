#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N = 100000;
int n;
int lst[N];
int sorted[N];
unordered_map<int, int> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		sorted[i] = lst[i];
		dic[lst[i]] = i;
	}
	sort(sorted, sorted + n);

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (lst[i] != sorted[i]) {
			int idx = dic[sorted[i]];
			swap(lst[i], lst[idx]);
			swap(dic[lst[i]], dic[lst[idx]]);
			cnt++;
		}
	}
	cout << cnt;
}