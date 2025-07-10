#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1e5;
int n;

struct Node {
	string var;
	int st, ed;
	Node* prev;
	Node* next;

	Node(string VAR, int ST, int ED) : var(VAR), st(ST), ed(ED), prev(nullptr), next(nullptr) {}
};
unordered_map<string, Node*> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	Node* root = new Node("root", 0, 0);

	while (n--) {
		string q; cin >> q;
		auto it1 = find(q.begin(), q.end(), '(');
		auto it2 = find(q.begin(), q.end(), ')');
		string inner = string(it1 + 1, it2);

		if (q.find("malloc") != string::npos) {
			string var = string(q.begin(), q.begin() + 4);
			int size = stoi(inner);
			
			Node* cur = root;
			while (1) {
				if (cur->next == nullptr) {
					//cout << cur->var << " " << cur->st << " " << cur->ed << "\n";
					int st = cur->ed + 1;
					int ed = cur->ed + size;

					if (ed <= M) {
						Node* node = new Node(var, st, ed);
						node->prev = cur;
						cur->next = node;
						dic[var] = node;
					}
					else dic[var] = nullptr;
					break;
				}

				int st = cur->ed + 1;
				int ed = cur->ed + size;
				//cout << cur->var << " " << cur->st << " " << cur->ed << " " << cur->next->var << " " << cur->next->st << " " << cur->next->ed << "\n";
				if (ed < cur->next->st) {
					Node* node = new Node(var, st, ed);

					node->next = cur->next;
					node->next->prev = node;

					node->prev = cur;
					cur->next = node;

					dic[var] = node;
					break;
				}
				cur = cur->next;
			}
		}
		else if (q.find("print") != string::npos) {
			auto it = dic.find(inner);
			if (it == dic.end() || !it->second) cout << 0 << "\n";
			else cout << it->second->st << "\n";
		}
		else {
			auto it = dic.find(inner);
			if (it == dic.end() || !it->second) continue;
			else {
				Node* node = it->second;

				if (node->next != nullptr) {
					node->prev->next = node->next;
					node->next->prev = node->prev;
				}
				else node->prev->next = nullptr;

				it->second = nullptr;
				delete node;
			}
		}
	}
}