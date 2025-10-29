#include<iostream>
#include<queue>
using namespace std;

int monts[] = { 0, 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int pre[14];
int n;
struct Date {
	int sd, ed;
	bool operator<(const Date& other) const {
		if (sd == other.sd) ed < other.ed;
		return sd > other.sd;
	}
};
priority_queue<Date> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i < 14; ++i) pre[i] = pre[i - 1] + monts[i];
	int s = pre[3] + 1, e = pre[12] + 1;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int sm, sd, em, ed; cin >> sm >> sd >> em >> ed;
		int sv = pre[sm] + sd;
		int ev = pre[em] + ed;
		if (ev < s || sv > e) continue;

		sv = max(sv, s);
		ev = min(ev, e);
		pq.push({ sv, ev });
	}

	if (pq.top().sd != s) {
		cout << 0;
		return 0;
	}

	int cur = pq.top().sd;
	int ans = 0;
	while (cur < e) {
		if (pq.empty()) {
			cout << 0;
			return 0;
		}

		int mx = -1;
		while (!pq.empty() && pq.top().sd <= cur) {
			Date date = pq.top(); pq.pop();
			//cout << cur << " " << date.sd << " " << date.ed << "\n";
			if (mx < date.ed) mx = date.ed;
		}

		if (mx == -1) {
			cout << 0;
			return 0;
		}

		cur = mx;
		ans++;
	}
	cout << ans;
}