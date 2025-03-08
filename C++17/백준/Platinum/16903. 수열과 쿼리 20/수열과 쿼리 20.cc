#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int MB = 32;
struct Trie {
	Trie* child[2];
	int cnt;
	Trie() {
		memset(child, 0, sizeof(child));
		cnt = 0;
	}
	~Trie() {
		if (child[0]) delete child[0];
		if (child[1]) delete child[1];
	}
};

void insert(Trie* root, const string& str) {
	Trie* cur = root;
	for (int i = 0; i < MB; ++i) {
		int bit = str[i] - '0';
		if (!cur->child[bit]) cur->child[bit] = new Trie();
		cur = cur->child[bit];
		cur->cnt++;
	}
}

void remove(Trie* root, const string& str) {
	Trie* cur = root;
	Trie* par[MB + 1];
	int bits[MB];
	par[0] = root;
	for (int i = 0; i < MB; ++i) {
		int bit = str[i] - '0';
		bits[i] = bit;
		cur = cur->child[bit];
		par[i + 1] = cur;
		cur->cnt--;
	}
	for (int i = MB; i > 0; --i) {
		if (!par[i]->cnt) {
			delete par[i];
			par[i - 1]->child[bits[i - 1]] = nullptr;
		}
	}
}

int XOR(Trie* root, const string& str){
	Trie* cur = root;
	int result = 0;
	for (int i = 0; i < MB; ++i) {
		int bit = str[i] - '0';
		if (cur->child[bit ^ 1]) {
			result += 1 << 31 - i;
			cur = cur->child[bit ^ 1];
		}
		else if (cur->child[bit]) cur = cur->child[bit];
		else break;
	}
	return result;
}

string trans(int n) {
	string s = "";
	for (int i = 31; i >= 0; --i) {
		if (n & (1 << i)) s += '1';
		else s += '0';
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Trie* root = new Trie();
	insert(root, trans(0));
	int m; cin >> m;
	while (m--) {
		int op, n; cin >> op >> n;
		string s = trans(n);
		if (op == 1) insert(root, s);
		else if (op == 2) remove(root, s);
		else cout << XOR(root, s) << "\n";
	}
}