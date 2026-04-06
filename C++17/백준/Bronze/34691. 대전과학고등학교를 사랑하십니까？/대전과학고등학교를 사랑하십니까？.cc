#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	string s;
	while ( cin >> s )
	{
		if ( s == "end" )
			break;

		cout << ( s == "animal" ? "Panthera tigris" : s == "flower" ? "Forsythia koreana" : "Pinus densiflora" ) << '\n';
	}
}