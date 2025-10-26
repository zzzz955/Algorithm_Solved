#include<iostream>
#include<unordered_map>
using namespace std;

const int N = 3e6;
int n, d, k, c;
int lst[N];
unordered_map<int, int> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	for (int i = 0; i < k; ++i) dic[lst[i]]++;
	int ans = dic.count(c) ? dic.size() : dic.size() + 1;

	int L = 0, R = k;
	for (int i = 0; i < n; ++i) {
		int del = lst[L];
		if (--dic[del] == 0) dic.erase(del);
		if (++L == n) L = 0;

		int add = lst[R];
		dic[add]++;
		if (++R == n) R = 0;

		int cnt = dic.count(c) ? dic.size() : dic.size() + 1;
		//cout << "==========\n";
		//for (const auto& j : dic) cout << j.first << ":" << j.second << "\n";
		//cout << ans << " " << cnt << "\n";
		ans = max(ans, cnt);
	}
	cout << ans;
}