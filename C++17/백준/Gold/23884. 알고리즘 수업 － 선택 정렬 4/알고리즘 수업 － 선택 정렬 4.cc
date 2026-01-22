#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 5e5;
int n, k;
int arr[N];
map<int, int> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int d; cin >> d;
		arr[i] = d;
		dic[d] = i;
	}

	for (int i = n - 1; i >= 0; --i) {
		auto [key, value] = *dic.rbegin();
		int cur = arr[i];

		//cout << key << " " << value << " " << cur << " " << k << "\n";
		if (key != cur) {
			swap(arr[i], arr[value]);
			dic[cur] = value;
			if (!--k) break;
		}

		dic.erase(--dic.end());
	}
	
	if (k) cout << -1;
	else for (int i = 0; i < n; ++i) cout << arr[i] << " ";
}