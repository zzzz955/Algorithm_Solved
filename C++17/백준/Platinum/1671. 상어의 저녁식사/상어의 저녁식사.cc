#include<iostream>
#include<vector>
using namespace std;

const int N = 51;
vector<int> edges[N];
struct Shark {
	int a, b, c;
};
Shark sharks[N];
int match[N];
int v[N];
int t;

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

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a, b, c; cin >> a >> b >> c;
		sharks[i] = { a, b, c };
	}

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			const Shark& s1 = sharks[i];
			const Shark& s2 = sharks[j];
			if (s1.a == s2.a && s1.b == s2.b && s1.c == s2.c) edges[i].push_back(j);
			else if (s1.a >= s2.a && s1.b >= s2.b && s1.c >= s2.c) edges[i].push_back(j);
			else if (s1.a <= s2.a && s1.b <= s2.b && s1.c <= s2.c) edges[j].push_back(i);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfs(i)) cnt++;
		t++;
		if (dfs(i)) cnt++;
	}
	cout << n - cnt;
}