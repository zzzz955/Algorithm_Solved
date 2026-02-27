#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const	uint8_t	 N = 51;
		uint8_t	 nodes[ N ];
		int		 n;
		int		 m;

struct Edge
{
	uint8_t f, t, w;
	bool operator<( const Edge& other ) const
	{
		return w < other.w;
	}
};
vector< Edge > edges;

int Find( uint8_t a )
{
	if ( nodes[ a ] == a )
		return a;
	return nodes[ a ] = Find( nodes[ a ] );
}

bool Union( uint8_t a, uint8_t b )
{
	uint8_t A = Find( a );
	uint8_t B = Find( b );

	if ( A == B )
		return false;

	nodes[ B ] = A;
	return true;
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	edges.reserve( 100 );
	while ( ( cin >> n ) && n )
	{
		cin >> m;
		edges.clear();
		for ( uint8_t i = 1; i <= n; ++i )
			nodes[ i ] = i;

		while ( m-- )
		{
			int f, t, w;
			cin >> f >> t >> w;
			edges.push_back( { 
				static_cast< uint8_t >( f ), 
				static_cast< uint8_t >( t ), 
				static_cast< uint8_t >( w ) 
				} );
		}

		sort( edges.begin(), edges.end() );
		uint16_t sum = 0;
		uint8_t	 cnt = 0;

		for ( const Edge& edge : edges )
		{
			const auto& [f, t, w] = edge;

			if ( Union( f, t ) )
			{
				sum += w;
				++cnt;
			}

			if ( cnt == n - 1 )
				break;
		}
		cout << sum << "\n";
	}
}