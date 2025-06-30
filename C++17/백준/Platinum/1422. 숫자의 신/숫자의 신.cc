#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

int k, n;
struct S {
	string cmp, def;
	bool operator<(const S& other) const {
		return cmp > other.cmp;
	}
};
vector<S> s1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;

	int mv = 0;
	for (int i = 0; i < k; ++i) {
		string def; cin >> def;
		mv = max(mv, stoi(def));
		string cmp = def;
		while (cmp.size() < 10) cmp += cmp;
		s1.push_back({cmp, def});
	}

	sort(s1.begin(), s1.end());
	string mvs = to_string(mv);
	string ans = "";
	int dup = n - k;
	for (const S& s : s1) {
		ans += s.def;
		if (dup > 0 && s.def == mvs) {
			while (dup--) ans += s.def;
		}
	}

	cout << ans;
}