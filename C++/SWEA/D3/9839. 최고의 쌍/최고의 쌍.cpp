#include <iostream>
using namespace std;

const int N = 1000;
int arr[ N ];

bool Check( int cur )
{
	int back = cur % 10;
	cur /= 10;
	//cout << cur << " " << cur / 10 << '\n';
	while ( cur )
	{
		int new_back = cur % 10;
		//cout << back << " " << new_back << '\n';
		if ( back - new_back != 1 )
			return false;
		
		back = new_back;
		cur /= 10;
	}

	return true;
}

int main()
{
	int tc, n;
	cin >> tc;

	for ( int t = 1; t <= tc; ++t )
	{
		cin >> n;
		for ( int i = 0; i < n; ++i )
			cin >> arr[ i ];

		int best = -1;
		for ( int i = 0; i < n - 1; ++i )
		{
			for ( int j = i + 1; j < n; ++j )
			{
				int cur = arr[ i ] * arr[ j ];
				if ( cur > best && Check( cur ) )
					best = cur;
			}
		}

		cout << "#" << t << " " << best << '\n';
	}
}