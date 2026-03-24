#include <iostream>
#include <vector>

using namespace std;

const int N = 101;
int n, s, ans;
int arr[ N ];
bool visit[ N ];
vector< int > can_use;

void Print( int cnt, vector< int >& maked )
{
	for ( int d : maked )
	{
		cout << d << " ";
	}
	cout << "cnt: " << cnt << '\n';
}

void BackTracking( int level, int cnt, vector< int >& maked )
{
	//Print( cnt, maked );

	if ( cnt > s )
		return;

	if ( level == n )
	{
		if ( cnt == s )
			++ans;

		return;
	}

	if ( arr[ level ] )
	{
		int add = 0;
		for ( int i = 0; i < static_cast< int >( maked.size() ); ++i )
		{
			if ( maked[ i ] < arr[ level ] )
				++add;
		}

		maked.push_back( arr[ level ] );
		BackTracking( level + 1, cnt + add, maked );
		maked.pop_back();
		return;
	}

	for ( int d : can_use )
	{
		if ( visit[ d ] )
			continue;

		int add = 0;
		for ( int i = 0; i < static_cast< int >( maked.size() ); ++i )
		{
			if ( maked[ i ] < d )
				++add;
		}

		visit[ d ] = true;
		maked.push_back( d );
		BackTracking( level + 1, cnt + add, maked );
		maked.pop_back();
		visit[ d ] = false;
	}
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n >> s;
	for ( int i = 0; i < n; ++i )
	{
		cin >> arr[ i ];
		visit[ arr[ i ] ] = true;
	}

	for ( int i = 1; i <= n; ++i )
	{
		if ( !visit[ i ] )
			can_use.push_back( i );
	}

	vector< int > maked;
	BackTracking( 0, 0, maked );

	cout << ans;
}