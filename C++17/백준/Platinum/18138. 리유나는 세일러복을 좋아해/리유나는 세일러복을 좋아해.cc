#include<iostream>
#include<vector>
using namespace std;

const int N = 201;
int T[N];
int K[N];
int n, m;
int M[N];
int v[N];
int t;
vector<int> edges[N];

bool dfs(int sn) {
	if (v[sn] == t) return false;
	v[sn] = t;

	for (int nn : edges[sn]) {
		if (!M[nn]) {
			M[nn] = sn;
			return true;
		}
	}

	for (int nn : edges[sn]) {
		if (dfs(M[nn])) {
			M[nn] = sn;
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> T[i];
	for (int i = 1; i <= m; ++i) cin >> K[i];
	for (int i = 1; i <= n; ++i) {
		int tw = T[i];
		for (int j = 1; j <= m; ++j) {
			int kw = K[j];
			if (((double)tw / 2 <= kw && kw <= (double)tw * 3 / 4) || (tw <= kw && kw <= (double)tw * 5 / 4)) {
				edges[i].push_back(j);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfs(i)) ans++;
	}
	cout << ans;
}