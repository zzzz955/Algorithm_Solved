#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
using pii = pair<int, int>;

const int N = 1e6 + 1;
int t, n, a, b;
bool primes[N];

void common(int nn, int nv, int flag, queue<pii>& q, unordered_set<int>& v) {
	switch (flag) {
		case 2: nn /= 2; break;
		case 3: nn /= 3; break;
		case 1: nn += 1; break;
		case -1: nn -= 1; break;
		default: break;
	}
	if (!v.count(nn)) {
		v.insert(nn);
		q.push({nn, nv});
	}
}

int bfs() {
	queue<pii> q;
	q.push({ n, 0 });
	unordered_set<int> v;
	v.insert(n);

	while (!q.empty()) {
		pii c = q.front(); q.pop();
		int cn = c.first, cv = c.second;
		if (!primes[cn] && a <= cn && cn <= b) return cv;

		common(cn, cv + 1, 2, q, v);
		common(cn, cv + 1, 3, q, v);
		common(cn, cv + 1, 1, q, v);
		if (cn) common(cn, cv + 1, -1, q, v);
	}
	return -1;
}

int main() {
	cin >> t;
	primes[0] = primes[1] = true;
	for (int i = 2; i * i < N; ++i) {
		if (primes[i]) continue;
		for (int j = i * i; j < N; j += i) primes[j] = true;
	}
	//for (int i = 0; i <= 100; ++i) cout << primes[i] << " ";

	while (t--) {
		cin >> n >> a >> b;
		bool chk = false;
		for (int i = a; i <= b; ++i) {
			if (!primes[i]) {
				chk = true;
				break;
			}
		}
		if (!chk) cout << -1 << "\n";
		else cout << bfs() << "\n";
	}
}