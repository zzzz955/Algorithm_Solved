#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5;
int t, n, m;
int arr_a[ N ], arr_b[ N ];

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> t;
	while ( t-- )
	{
		cin >> n >> m;

		for ( int i = 0; i < n; ++i )
			cin >> arr_a[ i ];

		for ( int i = 0; i < m; ++i )
			cin >> arr_b[ i ];

		sort( arr_a, arr_a + n );
		sort( arr_b, arr_b + m );

		int sum = 0;
		for ( int i = 0; i < m; ++i )
		{
			int cnt = arr_a + n - upper_bound( arr_a, arr_a + n, arr_b[ i ] );

			if ( !cnt ) 
				break;

			sum += cnt;
		}
			

		cout << sum << "\n";
	}
}