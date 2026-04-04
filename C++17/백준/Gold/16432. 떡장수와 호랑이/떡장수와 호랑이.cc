#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1000;
int n;
bool flag;
vector<int> edges[ N ];
bool visited[ N ][ 10 ];

void dfs( int level, vector<int>& stack )
{
	if ( flag )
		return;

	if ( level == n )
	{
		flag = true;

		for ( int i : stack )
			cout << i << '\n';

		return;
	}

	int last = stack.empty() ? 0 : stack.back();

	if ( visited[ level ][ last ] )
		return;

	for ( int i : edges[ level ] )
	{
		if ( !stack.empty() && stack.back() == i )
			continue;

		stack.push_back( i );
		dfs( level + 1, stack );
		stack.pop_back();

		if ( flag )
			return;
	}

	visited[ level ][ last ] = true;
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> n;
	for ( int i = 0; i < n; ++i )
	{
		int m; cin >> m;
		while ( m-- )
		{
			int d; cin >> d;
			edges[ i ].push_back( d );
		}
	}

	vector<int> stack;
	dfs( 0, stack );

	if ( !flag )
		cout << -1;
}