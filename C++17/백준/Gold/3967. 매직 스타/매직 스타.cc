#include<iostream>
#include<vector>
using namespace std;

struct Pos {
	int x, y;
};
Pos xp[13] = {
	{},
	{1, 5},
	{2, 2}, {2, 4}, {2, 6}, {2, 8},
	{3, 3}, {3, 7},
	{4, 2}, {4, 4}, {4, 6}, {4, 8},
	{5, 5}
};
bool v[13], u[13];
int c[7], s[7];
struct Group {
	int g1, g2;
};
Group g[13] = {
	{},
	{1, 3},
	{4, 6}, {1, 6}, {3, 6}, {5, 6},
	{1, 4}, {3, 5}, 
	{1, 2}, {2, 4}, {2, 5}, {2, 3},
	{4, 5}
};
char m[6][10];
bool flag;
vector<pair<Pos, char>> memo;

bool chk() {
	for (int i = 1; i < 7; ++i) {
		if (c[i] != 4 || s[i] != 26) return false;
	}
	return true;
}

void print() {
	for (const auto& data : memo) {
		m[data.first.x][data.first.y] = data.second;
	}

	for (int i = 1; i < 6; ++i) {
		for (int j = 1; j < 10; ++j) {
			cout << m[i][j];
		}
		cout << "\n";
	}
}

void bt(int level) {
	//print();
	if (flag) return;
	if (level == 13) {
		if (chk()) {
			print();
			flag = true;
		}
		return;
	}
	if (v[level]) bt(level + 1);
	//cout << level << "\n";

	const Group& group = g[level];
	const Pos& pos = xp[level];
	int x = pos.x, y = pos.y;

	for (int i = 1; i < 13; ++i) {
		if (u[i]) continue;

		u[i] = true;
		++c[group.g1];
		s[group.g1] += i;
		++c[group.g2];
		s[group.g2] += i;
		m[x][y] = 'A' + i - 1;

		bt(level + 1);

		u[i] = false;
		--c[group.g1];
		s[group.g1] -= i;
		--c[group.g2];
		s[group.g2] -= i;
		m[x][y] = 'x';
	}
}

int main() {
	for (int i = 1; i < 6; ++i) {
		for (int j = 1; j < 10; ++j) {
			cin >> m[i][j];
		}
	}
	
	for (int i = 1; i < 13; ++i) {
		const Group& group = g[i];
		const Pos& pos = xp[i];
		int x = pos.x, y = pos.y;
		if (m[x][y] == 'x') continue;

		//cout << m[x][y] << "\n";
		int val = m[x][y] - 'A' + 1;
		v[i] = true;
		u[val] = true;

		++c[group.g1];
		s[group.g1] += val;
		++c[group.g2];
		s[group.g2] += val;
		
		memo.push_back({ xp[i], m[x][y] });
	}
	
	//for (int i = 1; i < 13; ++i) cout << i << " : " << v[i] << "\n";
	bt(1);
}