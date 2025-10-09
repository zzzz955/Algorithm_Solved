#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;

int n;
unordered_map<string, int> s_to_i;
unordered_map<int, string> i_to_s;
unordered_map<int, vector<int>> edges;
unordered_map<int, int> cnt;
unordered_map<int, int> dep;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int idx = 0;
	cin >> n;
	while (n--) {
		string a, b; cin >> a >> b;

		if (!s_to_i.count(a)) {
			s_to_i[a] = idx;
			cnt[s_to_i[a]] = 0;
			i_to_s[idx++] = a;
		}

		if (!s_to_i.count(b)) {
			s_to_i[b] = idx;
			cnt[s_to_i[b]] = 0;
			i_to_s[idx++] = b;
		}

		int ai = s_to_i[a];
		int bi = s_to_i[b];
		edges[ai].push_back(bi);
	}

	for (const auto& edge : edges) {
		for (int nn : edge.second) {
			cnt[nn]++;
		}
	}

	queue<int> q;
	for (const auto& c : cnt) {
		if (!c.second) q.push(c.first);
	}

	set<pair<int, string>> order;
	while (!q.empty()) {
		int cn = q.front(); q.pop();
		order.insert({ dep[cn], i_to_s[cn] });

		for (const int nn : edges[cn]) {
			dep[nn] = max(dep[nn], dep[cn] + 1);
			if (!--cnt[nn]) q.push(nn);
		}
	}

	if (order.size() != edges.size()) {
		cout << -1;
		return 0;
	}

	for (const auto& cn : order) {
		cout << cn.second << "\n";
	}
}