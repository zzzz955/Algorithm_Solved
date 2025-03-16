#include<iostream>
#include<map>
#include<string>
#include<sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	map<string, int> dic;

	while (n--) {
		string s; cin >> s;
		stringstream ss(s);
		getline(ss, s, '.');
		getline(ss, s, '\n');
		dic[s]++;
	}
	for (const auto& i : dic) {
		cout << i.first << " " << i.second << "\n";
	}
}