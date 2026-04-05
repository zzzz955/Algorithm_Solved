#include <iostream>
using namespace std;

const int N = 3e5 + 1;
int n;
int nodes[ N ];

int Find( int a )
{
	if ( nodes[ a ] == a )
		return a;

	return nodes[ a ] = Find( nodes[ a ] );
}

void Union( int a, int b )
{
	int A = Find( a );
	int B = Find( b );

	if ( A == B )
		return;

	nodes[ B ] = A;
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n;
	for ( int i = 1; i <= n; ++i )
		nodes[ i ] = i;

	for ( int i = 0; i < n - 2; ++i )
	{
		int a, b; cin >> a >> b;
		Union( a, b );
	}

	int def = Find( 1 );
	for ( int i = 2; i <= n; ++i )
	{
		if ( def == Find( i ) )
			continue;

		cout << 1 << " " << i;
		return 0;
	}
}