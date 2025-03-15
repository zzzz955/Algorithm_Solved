#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

int n, c;
struct P {
	int v, c, i;
	bool operator<(const P& other) const {
		if (c == other.c) return i < other.i;
		return c > other.c;
	}
};
unordered_map<int, P> dic;
vector<P> lst;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		if (dic.count(a)) dic[a].c++;
		else dic[a] = { a, 1, i };
	}

	for (const auto& i : dic) lst.push_back(i.second);
	sort(lst.begin(), lst.end());

	for (int i = 0; i < lst.size(); ++i) {
		for (int j = 0; j < lst[i].c; ++j) {
			cout << lst[i].v << " ";
		}
	}
}