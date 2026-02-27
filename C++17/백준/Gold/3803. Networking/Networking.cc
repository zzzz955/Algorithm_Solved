#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 51;
int nodes[ N ];
int n, m;
struct Edge
{
	int f, t, w;
	bool operator<(const Edge& other) const
	{
		return w < other.w;
	}
};
vector<Edge> edges;

int Find( int a )
{
	if ( nodes[ a ] == a ) return a;
	return nodes[ a ] = Find( nodes[ a ] );
}

bool Union( int a, int b )
{
	int A = Find( a );
	int B = Find( b );
	if ( A == B ) return false;
	nodes[ B ] = A;
	return true;
}

int main() {
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	edges.reserve( 100 );
	while ( ( cin >> n ) && n )
	{
		cin >> m;
		edges.clear();
		for ( int i = 1; i <= n; ++i )
			nodes[ i ] = i;

		while ( m-- )
		{
			int f, t, w; cin >> f >> t >> w;
			edges.push_back( { f, t, w } );
		}

		sort( edges.begin(), edges.end() );
		int sum = 0, cnt = 0;
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