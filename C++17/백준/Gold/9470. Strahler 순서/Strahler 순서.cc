#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int t, k, m, p;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> k >> m >> p;
		vector<vector<int>> edges(m + 1);
		while (p--) {
			int a, b; cin >> a >> b;
			edges[a].push_back(b);
		}

		vector<int> cnt(m + 1);
		for (int i = 1; i <= m; ++i) {
			for (int j : edges[i]) cnt[j]++;
		}

		queue<int> q;
		vector<map<int, int>> maxdic(m + 1);
		vector<int> strahler(m + 1);
		for (int i = 1; i <= m;++i) {
			if (!cnt[i]) {
				q.push(i);
				maxdic[i][1] = 1;
			}
		}
		
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			auto it = --maxdic[cur].end();
			int max_val;
			if ((*it).second >= 2) max_val = (*it).first + 1;
			else max_val = (*it).first;
			strahler[cur] = max_val;

			//cout << "cur node : " << cur << ", edges : ";
			for (int i : edges[cur]) {
				//cout << i << " ";
				maxdic[i][max_val]++;
				if (!--cnt[i]) q.push(i);
			}
			//cout << "\n";
		}

		//for (int i = 1; i <= m; ++i) cout << "node " << i << " strahler : " << strahler[i] << "\n";
		cout << k << " " << strahler[m] << "\n";
	}
}