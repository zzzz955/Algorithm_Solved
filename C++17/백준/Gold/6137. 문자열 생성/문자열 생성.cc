#include<iostream>
#include<deque>
using namespace std;

deque<char> s;
string t;
char c;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		s.push_back(c);
	}

	while (!s.empty()) {
		char f = s.front();
		char b = s.back();

		if (f > b) {
			t += b;
			s.pop_back();
		}
		else if (f < b) {
			t += f;
			s.pop_front();
		}
		else {
			bool flag = true;
			auto l = s.begin();
			auto r = s.end();
			--r;

			while (l < r) {
				if (*l > *r) break;
				else if (*l < *r) {
					flag = false;
					break;
				}
				++l;
				--r;
			}

			if (flag) {
				t += b;
				s.pop_back();
			}
			else {
				t += f;
				s.pop_front();
			}
		}

		if (t.size() >= 80) {
			cout << t << "\n";
			t.clear();
		}
	}

	if (!t.empty()) cout << t;
}