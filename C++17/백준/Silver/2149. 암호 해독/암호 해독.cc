#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

string a, b;
struct IC {
	int idx;
	char ch;
	string str;
};
vector<IC> ics;

bool cmp_CH(const IC& left, const IC& right) {
	return left.ch < right.ch;
}

bool cmp_IDX(const IC& left, const IC& right) {
	return left.idx < right.idx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	int m = a.size();
	int n = b.size() / m;
	ics.resize(m);
	for (int i = 0; i < m; ++i) ics[i] = { i, a[i] };
	
	sort(ics.begin(), ics.end(), cmp_CH);
	for (int i = 0; i < m; ++i) {
		ics[i].str = string(b.begin() + i * n, b.begin() + i * n + n);
	}
	
	sort(ics.begin(), ics.end(), cmp_IDX);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ics[j].str[i];
		}
	}
}