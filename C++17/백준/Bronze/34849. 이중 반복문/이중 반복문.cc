#include <iostream>
using namespace std;

int main()
{
	long long n; cin >> n;
	cout << ( n * n <= 1ll * 1e8 ? "Accepted" : "Time limit exceeded" );
}