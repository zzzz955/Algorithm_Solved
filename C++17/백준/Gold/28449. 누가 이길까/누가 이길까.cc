#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
int hi[ N ];
int arc[ N ];
int dic[ N + 1 ];
int n, m;

static ll GetWinCount( int A[], int B[], int a, int b )
{
	ll winCount = 0;
	for ( int i = 0; i < a; ++i )
	{
		int d = A[ i ];
		auto ui = lower_bound( B, B + b, d );
		winCount += ui - B;
	}
	return winCount;
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for ( int i = 0; i < n; ++i )
	{
		cin >> hi[ i ];
		++dic[ hi[ i ] ];
	}
	
	ll draw = 0;
	for ( int i = 0; i < m; ++i )
	{
		cin >> arc[ i ];
		draw += dic[ arc[ i ] ];
	}

	sort( hi, hi + n );
	sort( arc, arc + m );

	ll win_hi = GetWinCount( hi, arc, n, m );
	ll win_arc = GetWinCount( arc, hi, m, n );

	cout << win_hi << " " << win_arc << " " << draw;
}