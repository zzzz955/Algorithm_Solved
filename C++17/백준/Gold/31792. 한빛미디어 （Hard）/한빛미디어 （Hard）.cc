#include<iostream>
#include<set>
using namespace std;

int q;
set<int> dic;
int cnt[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> q;
	while (q--) {
		int op; cin >> op;
		if (op != 3) {
			int price; cin >> price;
			if (op == 1) {
				if (dic.count(price)) cnt[price]++;
				else {
					dic.insert(price);
					cnt[price]++;
				}
			}
			else {
				if (dic.count(price)) {
					if (!--cnt[price]) dic.erase(price);
				}
			}
		}
		else {
			int cnt = 0;
			auto it = dic.begin();
			while (it != dic.end()) {
				cnt++;
				int price = *it;
				it = dic.lower_bound(price * 2);
			}
			cout << cnt << "\n";
		}
	}
}