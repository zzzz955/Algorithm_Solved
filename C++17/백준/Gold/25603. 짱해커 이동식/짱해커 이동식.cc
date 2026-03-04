#include <iostream>
using namespace std;

const int N = 1e5;
int n, k;
int arr[ N ];

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> n >> k;
	int mn = 0;
	for ( int i = 0; i < n; ++i )
	{
		cin >> arr[ i ];
		mn = max( mn, arr[ i ] );
	}

	int l = 1, r = mn, ans = mn;
	while ( l <= r )
	{
		int mid = ( l + r ) / 2;
		int cnt = 0;
		//cout << mid << " ";

		for ( int i = 0; i < n; ++i )
		{
			if ( arr[ i ] > mid )
				++cnt;
			else
				cnt = 0;

			if ( cnt >= k ) break;
		}

		//cout << cnt << "\n";

		if ( cnt >= k )
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
			ans = mid;
		}
	}
	cout << ans;
}