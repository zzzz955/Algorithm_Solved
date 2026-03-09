#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 1;
int n, m;
struct Edge
{
	int nn, nt;
};
vector< Edge > edges[ N ];
struct Pos
{
	int cn, cv, st;
	bool operator<( const Pos& other ) const
	{
		return cv > other.cv;
	}
};

int dijkstra( int sn, int en )
{
	priority_queue<Pos> pq;
	pq.push( { sn, 0, -1 } );
	vector< int > dist( n + 1, 1e5 );
	dist[ sn ] = 0;

	while ( !pq.empty() )
	{
		auto [ cn, cv, ct ] = pq.top(); pq.pop();
		if ( cv > dist[ cn ] ) 
			continue;

		if ( cn == en ) 
			return dist[ en ];

		for ( const auto& [ nn, nt ] : edges[ cn ] )
		{
			int nv = cv;
			if ( ct != -1 && ct != nt ) 
				++nv;

			if ( dist[ nn ] > nv )
			{
				dist[ nn ] = nv;
				pq.push( { nn, nv, nt } );
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n >> m;
	while ( m-- )
	{
		int f, t, v; cin >> f >> t >> v;

		edges[ f ].push_back( { t, v } );
		edges[ t ].push_back( { f, v } );
	}

	int sn, en; cin >> sn >> en;
	cout << dijkstra( sn, en );
}