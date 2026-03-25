#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1001;
int n, m, x;
struct Edge
{
	int nn, w;
};
vector < Edge > edges[ N ];
struct Pos
{
	int cn, cv;
	bool operator<( const Pos& other ) const
	{
		return cv > other.cv;
	}
};

int dijkstra()
{
	priority_queue< Pos > pq;
	pq.push( { x, 0 } );
	vector< int > dist( n + 1, 2e9 );
	dist[ x ] = 0;

	while ( !pq.empty() )
	{
		const auto [ cn, cv ] = pq.top(); pq.pop();
		if ( dist[ cn ] < cv ) 
			continue;

		for ( const auto& [nn, w] : edges[ cn ] )
		{
			int nv = cv + w;

			if ( dist[ nn ] > nv )
			{
				dist[ nn ] = nv;
				pq.push( { nn, nv } );
			}
		}
	}

	int mx = 0;
	for ( int i = 1; i <= n; ++i ) 
		mx = max( mx, dist[ i ] );
		

	return mx * 2;
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n >> m >> x;
	while ( m-- )
	{
		int f, t, w; cin >> f >> t >> w;
		edges[ f ].push_back( { t, w } );
		edges[ t ].push_back( { f, w } );
	}

	cout << dijkstra();
}