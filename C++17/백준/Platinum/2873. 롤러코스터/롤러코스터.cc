#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r, c; cin >> r >> c;
	int mn = 1000;
	int px = -1, py = -1;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			int d; cin >> d;
			if ((i + j) % 2 && d < mn) {
				mn = d;
				px = i, py = j;
			}
		}
	}

	string ans = "";
	if (r % 2) {
		for (int i = 0; i < r; ++i) {
			if (i % 2) ans += string(c - 1, 'L') + "D";
			else ans += string(c - 1, 'R') + "D";
		}
	}
	else if (c % 2) {
		for (int i = 0; i < c; ++i) {
			if (i % 2) ans += string(r - 1, 'U') + "R";
			else ans += string(r - 1, 'D') + "R";
		}
	}
	else {
		string f = "";
		for (int i = 0; i < px / 2; ++i) {
			f += string(c - 1, 'R') + "D";
			f += string(c - 1, 'L') + "D";
		}

		string m = "";
		bool flag = px % 2 ? true : false;
		int cx = px - flag, cy = 0;
		
		while (cx % 2 == 0 || cy != c - 1) {
			//cout << cx << " " << cy << "\n";
			if ((cx == px && cy + 1 == py)) {
				if (cx % 2) {
					--cx;
					m += "U";
				}
				else {
					++cx;
					m += "D";
				}
			}
			else if (cy == py || (!m.empty() && (m.back() == 'U' || m.back() == 'D'))) {
				++cy;
				m += "R";
			}
			else if ((!m.empty() && m.back() == 'R')) {
				if (cx % 2) {
					--cx;
					m += "U";
				}
				else {
					++cx;
					m += "D";
				}
			}
			else if (m.empty()) {
				++cx;
				m += "D";
			}
		}
		m += "D";

		string b = "";
		for (int i = (px + 2) / 2; i < r / 2; ++i) {
			b += string(c - 1, 'L') + "D";
			b += string(c - 1, 'R') + "D";
		}

		//cout << "f:" << f << " m:" << m << " b:" << b << "\n";
		ans += f + m + b;
	}
	ans.pop_back();
	cout << ans;
}