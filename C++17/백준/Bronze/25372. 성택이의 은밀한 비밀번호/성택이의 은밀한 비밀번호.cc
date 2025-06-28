#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, len; cin >> n;
    string s;
    while (n--) {
        cin >> s;
        len = s.size();
        if (6 <= len && len <= 9) cout << "yes\n";
        else cout << "no\n";
    }
}