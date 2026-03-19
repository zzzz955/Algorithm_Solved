#include <iostream>
using namespace std;
using pii = pair< int, int >;

const int N = 300;
int n, q;
pii pos[ N ];
int dist[ N ][ N ];

void Init()
{
	for ( int i = 0; i < n; ++i )
		for ( int j = 0; j < n; ++j )
			dist[ i ][ j ] = 2e9;

	for ( int i = 0; i < n; ++i )
	{
		int l, r; cin >> l >> r;
		pos[ i ] = { l, r };
	}

	for ( int i = 0; i < n - 1; ++i )
	{
		for ( int j = i + 1; j < n; ++j )
		{
			const auto& [il, ir] = pos[ i ];
			const auto& [jl, jr] = pos[ j ];

			if ( ( jl <= il && il <= jr ) ||
				( jl <= ir && ir <= jr ) ||
				( jl <= il && ir <= jr ) ||
				( il <= jl && jr <= ir ) )
			{
				dist[ i ][ j ] = 1;
				dist[ j ][ i ] = 1;
			}
		}
	}
}

void FloydWarshall()
{
	for ( int k = 0; k < n; ++k )
	{
		for ( int i = 0; i < n; ++i )
		{
			for ( int j = 0; j < n; ++j )
			{
				if ( dist[ i ][ k ] == 2e9 ||
					dist[ k ][ j ] == 2e9 )
					continue;

				dist[ i ][ j ] = min( dist[ i ][ j ], dist[ i ][ k ] + dist[ k ][ j ] );
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> n;
	Init();
	FloydWarshall();
	
	cin >> q;
	while ( q-- )
	{
		int f, t; cin >> f >> t;
		cout << (dist[--f][--t] != 2e9 ? dist[f][t] : -1 ) << '\n';
	}
}