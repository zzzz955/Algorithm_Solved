#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
using pii = pair<int, int>;

const int N = 1e5;
int n;
pii a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p, q; cin >> p >> q;
		a[i] = { p, q };
	}
	sort(a, a + n);

	set<int> b;
	for (int i = 0; i < n; ++i) b.insert(i);

	map<int, int> c;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < n; ++i) {
		int st = a[i].first, et = a[i].second;

		while (!pq.empty() && pq.top().first < st) {
			pii cur = pq.top(); pq.pop();
			b.insert(cur.second);
		}

		int idx = *b.begin();
		b.erase(b.begin());
		++c[idx];
		pq.push({ et, idx });
	}
	cout << c.size() << "\n";
	for (const auto& i : c) cout << i.second << " ";
}