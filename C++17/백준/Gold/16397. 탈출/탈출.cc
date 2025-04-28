#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

int n, t, g;
bool v[100000];
struct Cur {
	int x, y;
};

int bfs() {
	queue<Cur> q;
	q.push({ n, 0 });
	v[n] = true;

	while (!q.empty()) {
		Cur cur = q.front(); q.pop();
		int p = cur.x, ct = cur.y;

		if (ct > t) continue;
		if (p == g) return ct;
		//cout << p << " " << v[p] << "\n";
		
		if (p + 1 < 1e5 && !v[p + 1]) {
			v[p + 1] = true;
			q.push({ p + 1, ct + 1 });
		}

		if (p * 2 >= 1e5) continue;
		string b = to_string(p * 2);
		if (b[0] > '0') b[0]--;
		int B = stoi(b);
		if (B < 1e5 && !v[B]) {
			v[B] = true;
			q.push({ B, ct + 1 });
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