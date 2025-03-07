#include<iostream>
#include<set>
using namespace std;

const int MAX = 100001;
int n, m, k;
int N[MAX], M[MAX];
multiset<pair<int, int>> NV, MV;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> N[i];
		NV.insert({ N[i], i });
	}
	for (int i = 1; i <= m; ++i) {
		cin >> M[i];
		MV.insert({ M[i], i + n });
	}

	cin >> k;
	while (k--) {
		char op; cin >> op;
		if (op == 'U') {
			int a, b; cin >> a >> b;
			if (a <= n) {
				NV.erase({ N[a], a });
				N[a] = b;
				NV.insert({ b, a });
			}
			else {
				MV.erase({ M[a % n], a });
				M[a % n] = b;
				MV.insert({ b, a });
			}
		}
		else {
			cout << (*NV.begin()).second << " " << (*MV.begin()).second << "\n";
		}
	}
}