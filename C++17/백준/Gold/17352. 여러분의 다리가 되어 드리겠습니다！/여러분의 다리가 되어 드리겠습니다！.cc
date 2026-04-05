#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 3e5 + 1;
int n;
bool v[ N ];
vector< int > edges[ N ];

void bfs()
{
	queue< int > q;
	q.push( 1 );
	v[ 1 ] = true;

	while ( !q.empty() )
	{
		int cn = q.front(); q.pop();
		for ( int nn : edges[ cn ] )
		{
			if ( v[ nn ] )
				continue;

			v[ nn ] = true;
			q.push( nn );
		}
	}
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n;
	for ( int i = 0; i < n - 2; ++i )
	{
		int f, t; cin >> f >> t;
		edges[ f ].push_back( t );
		edges[ t ].push_back( f );
	}

	bfs();
	for ( int i = 2; i <= n; ++i )
	{
		if ( v[ i ] )
			continue;

		cout << 1 << " " << i;
		return 0;
	}
}