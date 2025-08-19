#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;
using pii = pair<int, int>;

int n;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		int s, e; cin >> s >> e;
		pq.push({ s, e });
	}

	int ans = 0;
	int w = pq.top().first;
	multiset<int> h;
	h.insert(pq.top().second);
	pq.pop();

	while (!pq.empty()) {
		pii c = pq.top(); pq.pop();
		int s = c.first, e = c.second;

		int back = *(--h.end());
		//cout << "back : " <<  back << "\n";
		if (back + 1 < s) {
			ans += (back - w + 1) * h.size();
			w = s;
			h.clear();
			h.insert(e);
			continue;
		}

		int front = *h.begin();
		//cout << "front : " << front << "\n";
		if (front < s) {
			h.erase(h.begin());
			h.insert(e);
		}
		else h.insert(e);
	}

	int back = *(--h.end());
	ans += (back - w + 1) * h.size();
	cout << ans;
}