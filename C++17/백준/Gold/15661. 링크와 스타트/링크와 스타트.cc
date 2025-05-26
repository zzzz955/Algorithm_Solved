#include<iostream>
#include<vector>
using namespace std;

const int N = 20;
int n, ans = 2e9;
int lst[N][N];

int get_stats(vector<int>& T) {
	int res = 0;
	for (int i : T) {
		for (int j : T) {
			res += lst[i][j];
		}
	}
	return res;
}

void dfs(int level, vector<int>& S, vector<int>& L) {
	if (level == n) {
		if (S.empty() || L.empty()) return;
		int Ss = get_stats(S);
		int Ls = get_stats(L);
		if (ans > abs(Ss - Ls)) ans = abs(Ss - Ls);
		return;
	}

	S.push_back(level);
	dfs(level + 1, S, L);
	S.pop_back();

	L.push_back(level);
	dfs(level + 1, S, L);
	L.pop_back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> lst[i][j];

	vector<int> S, L;
	dfs(0, S, L);
	cout << ans;
}