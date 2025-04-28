#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

int n, t, g;
unordered_map<int, int> v;

int bfs() {
	queue<int> q;
	q.push(n);
	v[n] = 0;

	while (!q.empty()) {
		int p = q.front(); q.pop();
		if (v[p] > t) continue;
		if (p == g) return v[p];
		//cout << p << " " << v[p] << "\n";
		
		if (p + 1 < 1e5 && !v.count(p + 1)) {
			v[p + 1] = v[p] + 1;
			q.push(p + 1);
		}

		if (p * 2 >= 1e5) continue;
		string b = to_string(p * 2);
		if (b[0] > '0') b[0]--;
		int B = stoi(b);
		if (B < 1e5 && !v.count(B)) {
			v[B] = v[p] + 1;
			q.push(B);
		}
	}
	return -1;
}

int main() {
	cin >> n >> t >> g;
	int res = bfs();
	if (res != -1) cout << res;
	else cout << "ANG";
}