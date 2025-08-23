#include<iostream>
#include<vector>
using namespace std;

const int N = 16;
int n, mp, mf, ms, mv;
vector<int> choose;
struct Info {
	int p, f, s, v;
};
Info infoes[N];
int costs[N];
int ans = 2e9;
vector<int> gets;

void do_best(int cc) {
	int cp = 0, cf = 0, cs = 0, cv = 0;
	for (int i : choose) {
		Info info = infoes[i];
		cp += info.p;
		cf += info.f;
		cs += info.s;
		cv += info.v;
	}

	if (cp >= mp && cf >= mf && cs >= ms && cv >= mv) {
		ans = cc;
		gets = choose;
	}
}

void bt(int level, int cost) {
	if (cost >= ans) return;
	do_best(cost);
	if (level > n) return;

	choose.push_back(level);
	bt(level + 1, cost + costs[level]);
	choose.pop_back();
	bt(level + 1, cost);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> mp >> mf >> ms >> mv;
	for (int i = 1; i <= n; ++i) {
		int p, f, s, v, c; cin >> p >> f >> s >> v >> c;
		infoes[i] = { p, f, s, v };
		costs[i] = c;
	}

	bt(1, 0);
	cout << (ans == 2e9 ? -1 : ans) << "\n";
	for (int i : gets) cout << i << " ";
}