#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
using pii = pair<int, int>;

struct Status {
	int l, r, cur, cnt;
};
string s;
int n, m;
char dt[] = { 'B', 'L', 'D' };
unordered_set<int> v;

bool can_eat(char cmp, char cur) {
	//cout << cmp << " " << cur << "\n";
	if (cmp == cur) return true;
	return false;
}

int bfs() {
	queue<Status> q;
	q.push({ 0, m - 1, 0, 0 });
	int mx = 0;

	while (!q.empty()) {
		auto [l, r, cur, cnt] = q.front(); q.pop();
		//cout << l << " " << r << " " << s[l] << " " << s[r] << " " << cur << " " << dt[cur] << " " << cnt << "\n";
		if (l > r) return m;
		if (mx < cnt) mx = cnt;

		if (!v.count(r * 10000 + l)) {
			if (can_eat(s[l], dt[cur])) {
				v.insert(r * 10000 + l);
				q.push({ l + 1, r, cur == 2 ? 0 : cur + 1, cnt + 1 });
			}

			if (can_eat(s[r], dt[cur])) {
				v.insert(r * 10000 + l);
				q.push({ l, r - 1, cur == 2 ? 0 : cur + 1, cnt + 1 });
			}
		}
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	m = s.size();
	cout << bfs();
}