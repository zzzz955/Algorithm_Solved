#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

unordered_map<int, int> dp;

int chk(int n) {
    if (dp[n]) return dp[n];

    int sqrtN = sqrt(n);
    set<vector<int>> unique;
    for (int a = 0; a <= sqrtN; a++) {
        for (int b = a; b <= sqrtN; b++) {
            for (int c = b; c <= sqrtN; c++) {
                int three = a * a + b * b + c * c;
                if (three > n) continue;

                int last = n - three;
                int d = sqrt(last);

                if (d * d == last && d >= c) {
                    vector<int> sq;
                    if (a > 0) sq.push_back(a * a);
                    if (b > 0) sq.push_back(b * b);
                    if (c > 0) sq.push_back(c * c);
                    if (d > 0) sq.push_back(d * d);

                    sort(sq.begin(), sq.end());
                    unique.insert(sq);
                }
            }
        }
    }
    return dp[n] = unique.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n && n != 0) {
        cout << chk(n) << "\n";
    }
}