#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int n, m;
struct Order {
	int l, r, c;
};
vector<Order> orders;
struct Cur {
	string cs;
	int cc;
	bool operator<(const Cur& other) const {
		return cc > other.cc;
	}
};
unordered_map<string, int> v;

int dijkstra(string st, const string& tar) {
	priority_queue<Cur> pq;
	pq.push({ st, 0 });
	v[st] = 0;

	while (!pq.empty()) {
		Cur cur = pq.top(); pq.pop();
		string cs = cur.cs;
		int cc = cur.cc;
		//cout << cs << " " << cc << " " << tar << "\n";
		if (cs == tar) return cc;

		for (const Order& order : orders) {
			string ns = cs;
			int nc = cc + order.c;
			swap(ns[order.l], ns[order.r]);

			auto it = v.find(ns);
			if (it != v.end() && it->second <= nc) continue;
			v[ns] = nc;
			pq.push({ ns, nc });
		}
	}
	return -1;
}

string to_str(const vector<int>& lst) {
	string temp = "";
	for (int i = 0; i < n; ++i) {
		if (lst[i] == 10) temp += '0';
		else temp += lst[i] + '0';
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> lst(n);
	for (int i = 0; i < n; ++i) cin >> lst[i];

	string st = to_str(lst);
	sort(lst.begin(), lst.end());
	string tar = to_str(lst);
	
	cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		orders.push_back({ --a, --b, c });
	}
	cout << dijkstra(st, tar);
}