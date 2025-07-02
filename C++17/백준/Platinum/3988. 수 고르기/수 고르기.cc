#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

const int N = 1e6;
int n, k;
int lst[N];
multiset<int> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	sort(lst, lst + n);

	int w = n - k;
	for (int i = 0; i < w - 1; ++i) dic.insert(lst[i + 1] - lst[i]);

	int M = lst[w - 1] - lst[0];
	int m = *dic.begin();
	int ans = M + m;

	for (int i = w; i < n; ++i) {
		dic.erase(dic.find(lst[i - w + 1] - lst[i - w]));

		M = lst[i] - lst[i - w + 1];
		dic.insert(lst[i] - lst[i - 1]);
		m = *dic.begin();
		ans = min(ans, M + m);
	}
	cout << ans;
}