#include<iostream>
#include<queue>
#include<unordered_map>
#define ll long long
using namespace std;

ll n;
unordered_map<ll, int> v;

void div(ll cur, int val, queue<ll>& q) {
	if (cur % val) return;
	ll next = val != 1 ? cur / val : cur - 1;
	auto it = v.find(next);
	if (it != v.end()) return;
	v[next] = v[cur] + 1;
	q.push(next);
}

int bfs() {
	queue<ll> q;
	q.push(n);
	v[n] = 0;

	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		//cout << cur << "\n";
		if (cur == 1) return v[cur];

		for (int i = 3; i >= 1; --i) div(cur, i, q);
	}
	return -1;
}

int main() {
	cin >> n;
	cout << bfs();
}