#include <iostream>
#include <algorithm>
using namespace	std;
using pii = pair< int, int >;

const int N = 1e6;
pii works[ N ];

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	int t; cin >> t;
	while ( t-- )
	{
		int n; cin >> n;
		for ( int i = 0; i < n; ++i )
		{
			int d, t; cin >> d >> t;
			works[ i ] = { t, d };
		}

		sort( works, works + n, greater< pii >() );

		int last_time = 1e9;
		for ( int i = 0; i < n; ++i )
		{
			const pii& work = works[ i ];
			int t = work.first;
			int d = work.second;

			if ( last_time > t )
				last_time = t;

			//cout << last_time << " ";
			last_time -= d;
		}
		//cout << last_time << '\n';

		cout << last_time << '\n';
	}
}