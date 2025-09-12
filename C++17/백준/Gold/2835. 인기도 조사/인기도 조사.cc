#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int N = 86400;
int n, q;
ll tree[N * 4];
ll lazy[N * 4];

pii parsing(const string& s) {
	int st = 0, et = 0;

	for (int i = 0; i < 8; i += 3) {
		string temp = s.substr(i, 2);
		switch (i) {
		case 0: st += stoi(temp) * 60 * 60; break;
		case 3: st += stoi(temp) * 60; break;
		default: st += stoi(temp);
		}
	}

	for (int i = 11; i < 19; i += 3) {
		string temp = s.substr(i, 2);
		switch (i) {
		case 11: et += stoi(temp) * 60 * 60; break;
		case 14: et += stoi(temp) * 60; break;
		default: et += stoi(temp);
		}
	}

	return { st, et };
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node]++;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R);
	update(node * 2 + 1, mid + 1, e, L, R);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, L, R) + query(node * 2 + 1, mid + 1, e, L, R);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin.get();
	while (n--) {
		string s;
		getline(cin, s);
		pii res = parsing(s);
		int st = res.first, et = res.second;

		if (st > et) {
			int diff = st - et;
			//cout << diff << "\n";
			update(1, 0, N - 1, st, N - 1);
			update(1, 0, N - 1, 0, et);
		}
		else update(1, 0, N - 1, st, et);
	}

	cin >> q;
	cin.get();
	cout << fixed << setprecision(10);
	while (q--) {
		string s;
		getline(cin, s);
		pii res = parsing(s);
		int st = res.first, et = res.second;
		double range = 0;
		ll sum = 0;

		if (st > et) {
			int diff = st - et;
			//cout << diff << "\n";
			range = N - diff + 1;
			sum += query(1, 0, N - 1, st, N - 1);
			sum += query(1, 0, N - 1, 0, st - diff);
		}
		else {
			range = et - st + 1;
			sum += query(1, 0, N - 1, st, et);
		}

		//cout << sum << " " << range << "\n";
		cout << sum / range << "\n";
	}
}