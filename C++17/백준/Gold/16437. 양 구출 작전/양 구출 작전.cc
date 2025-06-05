#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const int N = 123457;
int n;
ll ans;
ll val[N];
vector<int> children[N];

ll dfs(int node) {
    ll total = 0;

    for (int child : children[node]) {
        total += dfs(child);
    }

    if (node == 1) return total;

    if (val[node] >= 0) {
        return total + val[node];
    }
    else {
        return max(0LL, total + val[node]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; ++i) {
        char op;
        int cnt, next;
        cin >> op >> cnt >> next;

        val[i] = op == 'S' ? cnt : -cnt;
        children[next].push_back(i);
    }

    cout << dfs(1);
}