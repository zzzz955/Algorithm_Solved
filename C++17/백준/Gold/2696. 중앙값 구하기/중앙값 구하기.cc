#include<iostream>
#include<queue>
using namespace std;

int t, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> m;
		cout << (m + 1) / 2 << "\n";
		priority_queue<int, vector<int>, greater<int>> asc;
		priority_queue<int> desc;

		int outs = 0;
		for (int i = 1; i <= m; ++i) {
			int a; cin >> a;
			if (desc.empty()) desc.push(a);
			else if (asc.empty()) asc.push(a);
			else if (desc.top() > a) desc.push(a);
			else asc.push(a);

			if (!desc.empty() && !asc.empty() && desc.top() > asc.top()) {
				asc.push(desc.top());
				desc.pop();
			}

			if (desc.size() > asc.size() + 1) {
				asc.push(desc.top());
				desc.pop();
			}
			else if (desc.size() < asc.size()) {
				desc.push(asc.top());
				asc.pop();
			}

			if (i % 2) {
				cout << desc.top();
				if (++outs == 10) {
					cout << "\n";
					outs = 0;
				}
				else if (i != m) cout << " ";
			}
		}
		cout << "\n";
	}
}