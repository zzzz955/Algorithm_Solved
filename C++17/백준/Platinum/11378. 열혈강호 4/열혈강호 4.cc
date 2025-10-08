#include<iostream>
#include<vector>
using namespace std;

const int N = 1001;
int n, m, k;
int match[N];
int v[N];
int t;
vector<int> edges[N];

bool dfs(int cn) {
	for (int nn : edges[cn]) {
		if (!match[nn]) {
			match[nn] = cn;
			return true;
		}
	}

	for (int nn : edges[cn]) {
		if (v[nn] == t) continue;
		v[nn] = t;

		if (dfs(match[nn])) {
			match[nn] = cn;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		int c; cin >> c;
		while (c--) {
			int j; cin >> j;
			edges[i].push_back(j);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfs(i)) cnt++;
	}

	int add = 0;
	bool flag = true;
	while (add < k && flag) {
		flag = false;
		for (int i = 1; i <= n; ++i) {
			t++;
			if (dfs(i)) {
				cnt++;
				add++;
				flag = true;
				if (add == k) break;
			}
		}
	}

	cout << cnt;
}