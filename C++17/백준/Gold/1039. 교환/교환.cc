#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

string s, ans;
int k, l;
unordered_map<string, bool> v[11];
struct Info {
	string cur;
	int cnt;
};

void bfs() {
	queue<Info> q;
	q.push({ s, 0 });
	v[0][s] = true;

	while (!q.empty()) {
		Info info = q.front(); q.pop();
		string cur = info.cur;
		int cnt = info.cnt;
		if (cnt == k) {
			if (ans < cur) ans = cur;
			continue;
		}

		for (int i = 0; i < l - 1; ++i) {
			for (int j = i + 1; j < l; ++j) {
				string next = cur;
				swap(next[i], next[j]);
				if (next[0] == '0') continue;
				if (v[cnt + 1][next]) continue;
				v[cnt + 1][next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> s >> k;
	l = s.size();
	bfs();
	if (ans.empty()) cout << -1;
	else cout << ans;
}