#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair< int, int >;

const int N = 1e6;
int n, d, t, ans;
pii works[ N ];

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n;
	for ( int i = 0; i < n; ++i )
	{
		cin >> d >> t;
		works[ i ] = { t, d };
	}
	sort( works, works + n, greater< pii >() );

	int now = works[ 0 ].first;
	for ( int i = 0; i < n; ++i )
	{
		auto [ t, d ] = works[ i ];
		now = min( now, t ) - d;
	}

	ans = max( ans, now );

	cout << ans;
}