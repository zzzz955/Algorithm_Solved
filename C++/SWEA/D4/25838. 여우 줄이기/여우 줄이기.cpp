#include <iostream>
using namespace std;

const string target = "fox";

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	int t, n;
	string str;
	cin >> t;
	while ( t-- )
	{
		cin >> n >> str;
		string stack = "";

		for ( int i = 0; i < str.size(); ++i )
		{
			const char& c = str[ i ];
			stack.push_back( c );
			
			if ( c == 'x' )
			{
				int len = stack.size();
				if ( len >= 3 &&
					stack[ len - 3 ] == 'f' &&
					stack[ len - 2 ] == 'o' &&
					stack[ len - 1 ] == 'x' )
				{
					for ( int j = 0; j < 3; ++j )
						stack.pop_back();
				}
			}
		}

		cout << stack.size() << '\n';
	}
}