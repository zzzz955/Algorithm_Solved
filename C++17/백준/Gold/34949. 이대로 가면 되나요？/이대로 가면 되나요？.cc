#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int N = 2e5 + 1;
int n;
int dist[ N ];
vector< int > edges[ N ];

void bfs()
{
	queue< int > q;
	q.push( n );
	dist[ n ] = 0;

	while ( !q.empty() )
	{
		int cn = q.front(); q.pop();

		for ( int nn : edges[ cn ] )
		{
			if ( dist[ nn ] != -1 )
				continue;

			dist[ nn ] = dist[ cn ] + 1;
			q.push( nn );
		}
	}
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> n;
	memset( dist, -1, sizeof( dist ) );
	for ( int i = 1; i <= n; ++i )
	{
		int t; cin >> t;
		edges[ t ].push_back( i );
	}

	bfs();

	for ( int i = 1; i <= n; ++i )
		cout << dist[ i ] << '\n';
}