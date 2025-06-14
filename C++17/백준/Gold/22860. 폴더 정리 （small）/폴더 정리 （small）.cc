#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

unordered_map<string, short> folders;
unordered_map<string, short> files;
unordered_map<short, unordered_set<int>> childs;
vector<vector<int>> edges;
int f1, f2, total;

void dfs(int sn, unordered_set<int>& dic) {
	dic.insert(childs[sn].begin(), childs[sn].end());
	total += childs[sn].size();
	
	for (int nn : edges[sn]) {
		dfs(nn, dic);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;

	edges.resize(n + 1);
	for (int i = 0; i < n + m; ++i) {
		string a, b;
		int c;
		cin >> a >> b >> c;

		if (!folders.count(a)) folders[a] = f1++;
		if (c) {
			if (!folders.count(b)) folders[b] = f1++;
			edges[folders[a]].push_back(folders[b]);
		}
		else {
			if (!files.count(b)) files[b] = f2++;
			childs[folders[a]].insert(files[b]);
		}
	}

	//for (auto it : folders) cout << it.first << " " << it.second << "\n";

	int q; cin >> q;
	while (q--) {
		string a; cin >> a;
		string leaf;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != '/') leaf.push_back(a[i]);
			else leaf.clear();
		}

		unordered_set<int> dic;
		total = 0;
		dfs(folders[leaf], dic);
		//for (int i : dic) cout << i << " ";
		//cout << "\n";
		cout << dic.size() << " " << total << "\n";
	}
}