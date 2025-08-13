#include<iostream>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int t, a, b, ans;
bool v[5000001][2];
queue<pii> q;

void common(int n, bool flag) {
	if (n <= t && !v[n][flag]) {
		v[n][flag] = true;
		q.push({ n, flag });
		ans = max(ans, n);
	}
}

int main() {
	cin >> t >> a >> b;
	q.push({ 0, 0 });
	v[0][0] = true;

	while (!q.empty()) {
		pii c = q.front(); q.pop();
		int cv = c.first, cf = c.second;
		//cout << c << "\n";
		int A = cv + a, B = cv + b, C = cv / 2;
		common(A, cf);
		common(B, cf);
		if (!cf) common(C, true);
	}
	cout << ans;
}