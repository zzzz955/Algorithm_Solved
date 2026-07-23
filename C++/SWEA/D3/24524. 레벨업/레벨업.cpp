#include <iostream>
using namespace std;

const int N = 50;
int t, n;
int pos[ N ];
int mn_dist;

int Simulation( int vanish )
{
	int cur_pos = pos[ 0 ];
	int sum_dist = 0;

	for ( int i = 1; i < n - 1; ++i )
	{
		if ( i == vanish )
			continue;

		if ( sum_dist >= mn_dist )
			return mn_dist;

		sum_dist += abs( cur_pos - pos[ i ] );
		cur_pos = pos[ i ];
	}

	sum_dist += abs( cur_pos - pos[ n - 1 ] );

	return sum_dist;
}

int main()
{
	cin >> t;
	while ( t-- )
	{
		cin >> n;
		for ( int i = 0; i < n; ++i )
			cin >> pos[ i ];

		mn_dist = 1e9;
		for ( int i = 1; i < n - 1; ++i )
			mn_dist = min(mn_dist, Simulation( i ));

		cout << mn_dist << '\n';
	}
}