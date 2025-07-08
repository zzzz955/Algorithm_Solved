#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

const int N = 5e5 + 1;
const int BIT_SIZE = 2000000000 / 8 + 1;
char common_bitmap[BIT_SIZE];

int n, t;
unordered_set<int> user[N];
struct Card {
	int id;
	string op;
	int num;
};
Card hand[N];

inline bool is_set(int num) {
	return common_bitmap[num >> 3] & (1 << (num & 7));
}

inline void set_bit(int num) {
	common_bitmap[num >> 3] |= (1 << (num & 7));
}

inline void clear_bit(int num) {
	common_bitmap[num >> 3] &= ~(1 << (num & 7));
}

bool do_turn(int pid, Card card) {
	int id = card.id;
	string op = card.op;
	int num = card.num;

	if (op == "next") return true;

	if (op == "release") {
		user[pid].erase(num);
		clear_bit(num);
		return true;
	}

	if (!is_set(num)) {
		set_bit(num);
		user[pid].insert(num);
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> t;

	queue<int> turn;
	for (int i = 0; i < t; ++i) {
		int a; cin >> a;
		turn.push(a);
	}

	queue<Card> cards;
	for (int i = 0; i < t; ++i) {
		int id = 0;
		int num = 0;
		string op = "";
		cin >> id >> op;
		if (op != "next") cin >> num;

		cards.push({ id, op, num });
	}

	while (!turn.empty()) {
		int cu = turn.front(); turn.pop();

		if (!hand[cu].id) {
			Card card = cards.front(); cards.pop();
			cout << card.id << "\n";
			if (!do_turn(cu, card)) hand[cu] = card;
		}
		else {
			Card card = hand[cu];
			cout << card.id << "\n";
			if (do_turn(cu, card)) hand[cu] = { 0, "", 0 };
		}
	}
}
