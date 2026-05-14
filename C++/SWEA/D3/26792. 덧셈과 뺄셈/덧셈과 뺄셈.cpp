#include <iostream>
using namespace	std;

int t, x, y;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> t;
	while ( t-- )
	{
		cin >> x >> y;
		cout << ( x + y ) / 2 << " " << ( x - y ) / 2 << '\n';
	}
}