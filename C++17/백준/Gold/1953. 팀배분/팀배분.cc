#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 101;
int n;
bool v[N];
bool h[N][N];
vector<int> edges[N];
vector<int> TA, TB;
struct T {
	int cn;
	bool ct;
};

void bfs(int sn) {
	queue<T> q;
	q.push({ sn, true });
	TA.push_back(sn);

	while (!q.empty()) {
		T t = q.front(); q.pop();
		int cn = t.cn;
		bool ct = t.ct;

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;

			if (h[nn][cn]) {
				if (ct) TB.push_back(nn);
				else TA.push_back(nn);
				q.push({ nn, !ct });
			}
			else {
				TA.push_back(nn);
				q.push({ nn, ct });
			}
		}
	}
}

void print(vector<int>& T) {
	sort(T.begin(), T.end());
	cout << T.size() << "\n";
	for (int i : T) cout << i << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int c; cin >> c;
		while (c--) {
			int m; cin >> m;
			edges[i].push_back(m);
			h[i][m] = true;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (v[i]) continue;
		v[i] = true;
		bfs(i);
	}
	
	sort(TA.begin(), TA.end());
	sort(TB.begin(), TB.end());
	print(TA);
	print(TB);
}