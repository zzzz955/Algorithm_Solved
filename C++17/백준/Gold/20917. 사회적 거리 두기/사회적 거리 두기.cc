#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
int t, n, s;
int arr[ N ];

bool can( int d )
{
	int cnt = 1;
	int last = arr[ 0 ];
	for ( int i = 1; i < n && cnt < s; ++i )
	{
		if ( arr[ i ] - last >= d )
		{
			++cnt;
			last = arr[ i ];
		}
	}
	return cnt >= s;
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> t;
	while ( t-- )
	{
		cin >> n >> s;
		for ( int i = 0; i < n; ++i ) 
			cin >> arr[ i ];
		sort( arr, arr + n );

		int l = 0, r = arr[ n - 1 ], ans = 0;
		while ( l <= r )
		{
			int mid = ( l + r ) / 2;
			if ( can( mid ) )
			{
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
}