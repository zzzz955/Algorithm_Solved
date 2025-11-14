#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int q;
unordered_map<string, priority_queue<int>> dic;
long long ans;
int i, k, c, b;
string name;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;
	while (q--) {
		cin >> i >> name;

		if (i == 1) {
			cin >> k;
			priority_queue<int>& v = dic[name];

			while (k--) {
				cin >> c;
				v.push(c);
			}
		}
		else {
			cin >> b;
			priority_queue<int>& v = dic[name];

			while (!v.empty() && b--) {
				ans += v.top();
				v.pop();
			}
		}
	}
	cout << ans;
}