#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#define ull unsigned long long
using namespace std;

const ull MOD = 1000000007;
const int N = 1001;
int n, q;
string nodes[N];
bool v[N];
vector<int> edges[N];
struct P {
	int cn;
	string cv;
};

string bfs(int sn, int en) {
	queue<P> q;
	q.push({ sn, nodes[sn] });
	v[sn] = true;

	while (!q.empty()) {
		P p = q.front(); q.pop();
		int cn = p.cn;
		string cv = p.cv;
		if (cn == en) return cv;

		for (int nn : edges[cn]) {
			if (v[nn]) continue;
			v[nn] = true;
			string nv = cv + nodes[nn];
			ull nvi = stoull(nv);
			if (nvi > MOD) nv = to_string(nvi % MOD);
			//cout << nv << "\n";
			q.push({ nn, nv });
		}
	}
	return "-1";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> nodes[i];
	for (int i = 1; i <= n - 1; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	while (q--) {
		int a, b; cin >> a >> b;
		memset(v, 0, sizeof(v));
		cout << bfs(a, b) << "\n";
	}
}