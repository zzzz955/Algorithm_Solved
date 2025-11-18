#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int matching(const vector<int>& ws, const vector<int>& wt) {
	int match = 0;
	int s_idx = 0;
	int t_idx = 0;
	int ss = ws.size();
	int ts = wt.size();
	while (s_idx < ss && t_idx < ts) {
		int mh = ws[s_idx];
		int wh = wt[t_idx];

		if (wh < mh) {
			++match;
			++s_idx;
			++t_idx;
		}
		else ++s_idx;
	}
	return match;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> sm, tm, sw, tw;
	for (int i = 0; i < n; ++i) {
		int h; cin >> h;
		if (h < 0) sm.push_back(-h);
		else tm.push_back(h);
	}

	for (int i = 0; i < n; ++i) {
		int h; cin >> h;
		if (h < 0) sw.push_back(-h);
		else tw.push_back(h);
	}

	sort(sm.begin(), sm.end());
	sort(tm.begin(), tm.end());
	sort(sw.begin(), sw.end());
	sort(tw.begin(), tw.end());

	cout << matching(sm, tw) + matching(sw, tm);
}