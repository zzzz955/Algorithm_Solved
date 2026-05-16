#include <iostream>
using namespace	std;

int t, x;
string s;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> t;
	while ( t-- )
	{
		cin >> x;
		s.clear();
		
		if ( x == 1 )
			s = "0";
		else if ( x % 2 )
			s = "4";

		for ( int i = 0; i < x / 2; ++i )
			s += "8";

		cout << s << '\n';
	}
}