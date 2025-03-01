#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 100001;
int t, n, cnt;
int lst[N];
int v[N];
bool cycle[N];

void dfs(int node) {
	v[node] = 1;

	int next = lst[node];
	if (v[next] == 0) dfs(next);
	else if (v[next] == 1) {
		cycle[next] = true;

		int cur = next;
		while (cur != node) {
			cur = lst[cur];
			cycle[cur] = true;
		}
		cycle[node] = true;
	}
	v[node] = 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> lst[i];

		memset(v, 0, sizeof(v));
		memset(cycle, 0, sizeof(cycle));
		for (int i = 1; i <= n; ++i) {
			if (!v[i]) dfs(i);
		}

		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (!cycle[i]) cnt++;
		}
		cout << cnt << "\n";
	}
}