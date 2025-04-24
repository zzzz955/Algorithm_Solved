#include<iostream>
#include<queue>
#include<unordered_set>
#define ll long long
using namespace std;

const int M = 1e9;
ll s, t;
unordered_set<ll> v;

struct P {
	ll v;
	string s;
};

string bfs() {
	queue<P> q;
	q.push({ s * s, "*" });
	v.insert(s * s);
	q.push({ s * 2, "+" });
	v.insert(s * 2);
	q.push({ 0, "-" });
	v.insert(0);
	q.push({ 1, "/" });
	v.insert(1);

	while (!q.empty()) {
		P p = q.front(); q.pop();
		ll c = p.v;
		string s = p.s;
		if (c == t) return s;

		ll nv = c * c;
		if (nv <= t && !v.count(nv)) {
			v.insert(nv);
			q.push({ nv, s + '*' });
		}

		nv = c + c;
		if (nv <= t && !v.count(nv)) {
			v.insert(nv);
			q.push({ nv, s + '+' });
		}
	}
	return "-1";
}

int main() {
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}
	cout << bfs();
}