#include <iostream>
using namespace std;
using ll = long long;

int t, n, d;

int main()
{
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		cin >> n;
		ll mn = 1e6, mx = 2;

		while ( n-- )
		{
			cin >> d;
			mn = d < mn ? d : mn;
			mx = d > mx ? d : mx;
		}

		cout << "#" << tc << " " << mn * mx << '\n';
	}
}