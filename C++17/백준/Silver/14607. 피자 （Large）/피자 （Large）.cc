#include<iostream>
#include<queue>
#include<unordered_map>
#define ll long long
using namespace std;

int n;
unordered_map<int, ll> dic;

ll dfs(int num) {
	if (num == 1) return 0;
	if (dic[num]) return dic[num];

	ll l = num % 2 ? num / 2 + 1 : num / 2;
	ll r = num / 2;

	dic[num] = l * r;
	dic[num] += dfs(l);
	dic[num] += dfs(r);
	return dic[num];
}

int main() {
	cin >> n;
	cout << dfs(n);	
}