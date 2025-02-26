#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<double, bool> z;
unordered_map<double, bool> one;
unordered_map<double, bool> two;
unordered_map<double, bool> three;
unordered_map<double, bool> four;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int x, y; cin >> x >> y;
		if (!x && y < 0) z[-10001] = true;
		else if (!x && y > 0) z[10001] = true;
		else if (x < 0 && !y) z[-10002] = true;
		else if (x > 0 && !y) z[10002] = true;
		else {
			if (x > 0 && y > 0) one[(double)x / y] = true;
			if (x < 0 && y > 0) two[(double)x / y] = true;
			if (x < 0 && y < 0) three[(double)x / y] = true;
			if (x > 0 && y < 0) four[(double)x / y] = true;
		}
	}
	cout << z.size() + one.size() + two.size() + three.size() + four.size();
}
