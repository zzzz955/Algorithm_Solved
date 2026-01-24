#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e3;
int a, b, c;
int as[N], bs[N], cs[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    for (int i = 0; i < a; ++i) cin >> as[i];
    for (int i = 0; i < b; ++i) cin >> bs[i];
    for (int i = 0; i < c; ++i) cin >> cs[i];

    sort(as, as + a);
    sort(bs, bs + b);
    sort(cs, cs + c);

    int i = 0, j = 0, k = 0;
    int ans = 2e9;

    while (i < a && j < b && k < c) {
        int mn = min({ as[i], bs[j], cs[k] });
        int mx = max({ as[i], bs[j], cs[k] });

        ans = min(ans, mx - mn);

        if (mn == as[i]) i++;
        else if (mn == bs[j]) j++;
        else k++;
    }

    cout << ans;
}