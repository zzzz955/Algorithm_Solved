#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair< int, int >;

const int N = 2e5 + 1;
int n, r, mn, mpn, r_to_m, mx_dist;
vector< pii > edges[ N ];

void FindMiddleNodeAndDist( int cn, int pn, int dist )
{
	if (
		edges[ cn ].size() >= 2 && cn == r ||
		edges[ cn ].size() >= 3 ||
		( edges[ cn ].size() == 1 && cn != r )
		)
	{
		mn = cn;
		mpn = pn;
		r_to_m = dist;
		return;
	}

	for ( const auto& [ nn, w ] : edges[ cn ] )
	{
		if ( nn == pn ) continue;
		FindMiddleNodeAndDist( nn, cn, dist + w );
	}
}

void FindLongestDistToLeafNode( int cn, int pn, int dist )
{
	if ( edges[ cn ].size() == 1 && cn != mn )
	{
		mx_dist = max( mx_dist, dist );
		return;
	}

	for ( const auto& [ nn, w ] : edges[ cn ] )
	{
		if ( nn == pn ) continue;
		FindLongestDistToLeafNode( nn, cn, dist + w );
	}
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie(0);

	cin >> n >> r;
	for ( int i = 0; i < n - 1; ++i )
	{
		int f, t, w; cin >> f >> t >> w;
		edges[ f ].push_back( { t, w } );
		edges[ t ].push_back( { f, w } );
	}

	FindMiddleNodeAndDist( r, -1, 0 );
	FindLongestDistToLeafNode( mn, mpn, 0 );
	//cout << mn << " ";
	cout << r_to_m << " " << mx_dist;
}