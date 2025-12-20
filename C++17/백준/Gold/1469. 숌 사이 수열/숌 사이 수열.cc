#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> path;
vector<int> ap;
bool flag;
int cnt[17];

void bt(int level) {
	if (flag) return;
	if (level == n * 2) {
		for (int i : path) cout << i << " ";
		flag = true;
		return;
	}

	for (int i : ap) {
		if (cnt[i] > 1) continue;
		else if (cnt[i] == 0) {
			++cnt[i];
			path.push_back(i);
			bt(level + 1);
			path.pop_back();
			--cnt[i];
		}
		else {
			int len = path.size();
			if (len - i - 1 >= 0 && path[len - i - 1] == i) {
				++cnt[i];
				path.push_back(i);
				bt(level + 1);
				path.pop_back();
				--cnt[i];
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		ap.push_back(a);
	}
	sort(ap.begin(), ap.end());
	bt(0);
	if (!flag) cout << -1;
}