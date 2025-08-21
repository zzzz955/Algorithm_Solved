#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
using pii = pair<int, int>;

const int N = 2e5;
int n;
pii lst[N];
unordered_set<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, r; cin >> x >> r;
		lst[i] = { x - r, x + r };
		if (v.count(x - r) || v.count(x + r)) {
			cout << "NO";
			return 0;
		}
		v.insert(x - r);
		v.insert(x + r);
	}
	sort(lst, lst + n);

	vector<pii> stack;
	stack.push_back(lst[0]);
	for (int i = 1; i < n; ++i) {
		if (lst[i].first <= stack.back().second && stack.back().second <= lst[i].second) {
			cout << "NO";
			return 0;
		}
		while (!stack.empty() && stack.back().second < lst[i].first) stack.pop_back();
		stack.push_back(lst[i]);
	}
	cout << "YES";
}