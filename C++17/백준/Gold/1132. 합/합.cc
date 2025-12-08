#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 50;
ll w[10];
bool f[10];
bool v[10];
int n;
int val[10];
string words[N];

bool cmp(int a, int b) {
    return w[a] > w[b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> words[i];

    for (int i = 0; i < n; ++i) {
        const string& s = words[i];
        int len = s.size();
        f[s[0] - 'A'] = true;

        ll p = 1;
        for (int i = len - 1; i >= 0; --i) {
            int idx = s[i] - 'A';
            v[idx] = true;
            w[idx] += p;
            p *= 10;
        }
    }

    vector<int> letters;
    for (int i = 0; i < 10; ++i) {
        if (v[i]) letters.push_back(i);
    }

    int zero = -1;
    if (letters.size() >= 10) {
        ll mn = 1e18;
        for (int idx : letters) {
            if (!f[idx] && w[idx] < mn) {
                mn = w[idx];
                zero = idx;
            }
        }
    }

    sort(letters.begin(), letters.end(), cmp);

    int d = 9;
    for (int idx : letters) {
        if (idx == zero) continue;
        val[idx] = d--;
    }

    ll ans = 0;
    for (int i = 0; i < 10; ++i) {
        if (v[i]) ans += w[i] * val[i];
    }

    cout << ans;
}
