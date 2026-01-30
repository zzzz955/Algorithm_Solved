#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 501;
int arr[N];
vector<int> edges[N];
int n, m, t;
int v[N];
int match[N];

int get_gcd(int a, int b) {
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

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
	cout.tie(0);

	while (1) {
		cin >> n >> m;
		if (!n && !m) break;

		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
			edges[i].clear();
		}

		for (int i = 1; i <= m; ++i) {
			int a; cin >> a;

			for (int j = 1; j <= n; ++j) {
				int g = get_gcd(arr[j], a);
				if (g == 1) continue;

				edges[j].push_back(i);
			}
		}

		int ans = 0;
		memset(match, 0, sizeof(match));
		for (int i = 1; i <= n; ++i, ++t) {
			if (dfs(i)) ++ans;
		}
		cout << ans << "\n";
	}
}