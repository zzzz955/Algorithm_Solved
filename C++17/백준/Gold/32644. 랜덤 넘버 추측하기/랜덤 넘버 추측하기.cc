#include <iostream>
using namespace std;

const int N = 5e5 + 1;
int n, m;
int arr[ N ];
int tree[ N * 4 ];

void build( int node, int s, int e )
{
	if ( s == e ) 
		tree[ node ] = arr[ s ];
	else
	{
		int mid = ( s + e ) / 2;

		build( node * 2, s, mid );
		build( node * 2 + 1, mid + 1, e );

		tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
	}
}

void update( int node, int s, int e, int idx )
{
	if ( s == e ) 
		tree[ node ] = 0;
	else
	{
		int mid = ( s + e ) / 2;

		if ( idx <= mid ) 
			update( node * 2, s, mid, idx );
		else 
			update( node * 2 + 1, mid + 1, e, idx );

		tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
	}
}

int query( int node, int s, int e, int L, int R )
{
	if ( R < s || e < L ) 
		return 0;

	if ( L <= s && e <= R ) 
		return tree[ node ];

	int mid = ( s + e ) / 2;

	return query( node * 2, s, mid, L, R ) + query( node * 2 + 1, mid + 1, e, L, R );
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> n >> m;
	for ( int i = 1; i <= n; ++i )
		cin >> arr[ i ];

	build( 1, 1, n );

	while ( m-- )
	{
		int c; cin >> c;
		cout << query( 1, 1, n, 1, c - 1 ) + 1 << " ";
		update( 1, 1, n, c );
	}
	//cout << query( 1, 1, n, 1, n );
}