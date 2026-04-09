#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 1;
int n, m;
int nodes[ N ];
int troops[ N ];

int Find( int a )
{
	if ( nodes[ a ] == a )
		return a;

	return nodes[ a ] = Find( nodes[ a ] );
}

void Ally( int a, int b )
{
	int A = Find( a );
	int B = Find( b );
	nodes[ B ] = A;
	troops[ A ] += troops[ B ];
	troops[ B ] = 0;
}

void War( int a, int b )
{
	int A = Find( a );
	int B = Find( b );
	if ( troops[ A ] > troops[ B ] )
	{
		troops[ A ] -= troops[ B ];
		troops[ B ] = 0;
		nodes[ B ] = A;
	}
	else if ( troops[ A ] < troops[ B ] )
	{
		troops[ B ] -= troops[ A ];
		troops[ A ] = 0;
		nodes[ A ] = B;
	}
	else
	{
		troops[ A ] = 0;
		troops[ B ] = 0;
	}
}

void GetStatus()
{
	for ( int i = 1; i <= n; ++i )
	{
		cout << troops[ i ] << " ";
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> n >> m;
	for ( int i = 1; i <= n; ++i )
	{
		cin >> troops[ i ];
		nodes[ i ] = i;
	}

	while ( m-- )
	{
		int o, p, q; cin >> o >> p >> q;
		if ( p > q )
			swap( p, q );

		if ( o == 1 )
			Ally( p, q );
		else
			War( p, q );

		//GetStatus();
	}

	int country = 0;
	vector< int > remainTroops;
	for ( int i = 1; i <= n; ++i )
	{
		if ( troops[ i ] )
		{
			++country;
			remainTroops.push_back( troops[ i ] );
		}
	}
	sort( remainTroops.begin(), remainTroops.end() );

	cout << country << '\n';
	for ( int i : remainTroops )
		cout << i << " ";
}