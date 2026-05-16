#include <iostream>
using namespace	std;

int t, x;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> t;
	while ( t-- )
	{
		cin >> x;
		
		if ( x == 1 )
			cout << "0";
		else if ( x % 2 )
			cout << "4";

		for ( int i = 0; i < x / 2; ++i )
			cout << "8";

		cout << '\n';
	}
}