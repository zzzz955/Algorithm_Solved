#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

int n, q, k;
deque<int> deq;
struct OP {
	int op, val;
};
OP ops[100000];
int last1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q >> k;
	for (int i = 0; i < q; ++i) {
		int op; cin >> op;
		if (op == 0) {
			int num; cin >> num;
			ops[i] = { op, num };
		}
		else if (op == 1) {
			ops[i] = { op };
			last1 = i;
		}
		else if (op == 2) {
			ops[i] = { op };
		}
	}

	for (int i = 0; i < q; ++i) {
		const OP& op = ops[i];
		if (op.op == 0) deq.push_front(op.val);
		else if (op.op == 1 && i == last1) sort(deq.begin(), deq.end());
		else if (op.op == 2 && i > last1) reverse(deq.begin(), deq.end());
	}
	cout << deq[k - 1];
}