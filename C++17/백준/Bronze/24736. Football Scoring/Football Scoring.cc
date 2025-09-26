#include<iostream>
using namespace std;
int t, f, s, p, c;
int main() {
    while (cin >> t) {
        cin >> f >> s >> p >> c;
        cout << t * 6 + f * 3 + s * 2 + p + c * 2 << " ";
    }
}