#include<iostream>
#include<queue>
using namespace std;

const int N = 1 << 11;
int l, k;
int v[N];

int bfs() {
	queue<int> q;
	q.push(l);
	v[l] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == k) return v[cur];

		if (!v[cur + 1]) {
			v[cur + 1] = v[cur] + 1;
			q.push(cur + 1);
		}

		if (cur - 1 >= 0 && !v[cur - 1]) {
			v[cur - 1] = v[cur] + 1;
			q.push(cur - 1);
		}

		bool fz = true;
		for (int i = 10; i >= 0; --i) {
			int bit = 1 << i;
			if (fz && !(cur & bit)) continue;
			if (fz && (cur & bit)) {
				fz = false;
				continue;
			}
			int next = cur ^ bit;
			if (v[next]) continue;
			v[next] = v[cur] + 1;
			q.push(next);
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b; cin >> a >> b;

	int len_a = a.size();
	for (int i = len_a - 1; i >= 0; --i) {
		if (a[i] == '1') l |= 1 << len_a - i - 1;
	}

	int len_b = b.size();
	for (int i = len_b - 1; i >= 0; --i) {
		if (b[i] == '1') k |= 1 << len_b - i - 1;
	}

	cout << bfs();
}