#include<iostream>
#include<vector>
using namespace std;

const int N = 301;
int n, m, k1, k2, a1, a2;
vector<int> ek1[N], ek2[N];
int vk1[N], vk2[N];
int mk1[N], mk2[N];
int t;

bool dfsk1(int node) {
	for (int nn : ek1[node]) {
		if (vk1[nn] == t) continue;
		vk1[nn] = t;
		if (!mk1[nn] || dfsk1(mk1[nn])) {
			mk1[nn] = node;
			return true;
		}
	}
	return false;
}

bool dfsk2(int node) {
	for (int nn : ek2[node]) {
		if (vk2[nn] == t) continue;
		vk2[nn] = t;
		if (!mk2[nn] || dfsk2(mk2[nn])) {
			mk2[nn] = node;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k1 >> k2;
	while (k1--) {
		int i, j; cin >> i >> j;
		ek1[i].push_back(j);
	}

	while (k2--) {
		int i, j; cin >> i >> j;
		ek2[i].push_back(j);
	}

	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfsk1(i)) a1++;
	}

	for (int i = 1; i <= n; ++i) {
		t++;
		if (dfsk2(i)) a2++;
	}

	cout << (a1 < a2 ? "네 다음 힐딱이" : "그만 알아보자");
}