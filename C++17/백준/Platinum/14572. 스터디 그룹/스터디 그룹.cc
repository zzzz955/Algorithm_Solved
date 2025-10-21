#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

const int N = 1e5;
int n, k, d;
struct Student {
	int idx, e;
	bool operator<(const Student& other) const {
		return e < other.e;
	}
};
Student lst[N];
vector<int> algo[N];
unordered_map<int, int> dic;

void add(int idx) {
	const Student& student = lst[idx];
	for (int i : algo[student.idx]) {
		dic[i]++;
	}
}

void del(int idx) {
	const Student& student = lst[idx];
	for (int i : algo[student.idx]) {
		dic[i]--;
		if (!dic[i]) dic.erase(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> d;
	for (int i = 0; i < n; ++i) {
		int m, e; cin >> m >> e;
		lst[i] = {i, e};
		while (m--) {
			int a; cin >> a;
			algo[i].push_back(a);
		}
	}

	sort(lst, lst + n);
	int l = 0, r = 0;
	long long ans = 0;
	add(0);

	while (++r < n) {
		add(r);
		while (lst[r].e - lst[l].e > d) {
			del(l);
			++l;
		}

		int cnt = r - l + 1;
		int p1 = dic.size();
		int p2 = 0;
		for (const auto& i : dic) {
			if (i.second == cnt) p2++;
		}
		long long e = 1ll * (p1 - p2) * cnt;
		ans = max(ans, e);
		//cout << cnt << " " << p1 << " " << p2 << " " << e << " ";
	}
	cout << ans;
}