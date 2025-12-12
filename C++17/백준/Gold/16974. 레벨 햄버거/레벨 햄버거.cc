#include<iostream>
using namespace std;
using ll = long long;

ll s[51], p[51];

ll eat(int level, ll x) {
    if (x <= 0) return 0;
    if (level == 0) return 1;

    if (x == 1) return 0;

    if (x <= 1 + s[level - 1]) {
        return eat(level - 1, x - 1);
    }

    if (x == 1 + s[level - 1] + 1) {
        return p[level - 1] + 1;
    }

    if (x <= 1 + s[level - 1] + 1 + s[level - 1]) {
        return p[level - 1] + 1 + eat(level - 1, x - (1 + s[level - 1] + 1));
    }

    return p[level];
}

int main() {
    int n;
    ll x;
    cin >> n >> x;

    s[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }

    cout << eat(n, x);
}
