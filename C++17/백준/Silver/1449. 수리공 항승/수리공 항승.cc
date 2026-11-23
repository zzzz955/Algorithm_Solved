#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3 + 5;
int n, l;
int arr[ N ];

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> l;
	l *= 2;
	for ( int i = 0; i < n; ++i )
	{
		int d; cin >> d;
		arr[ i ] = d * 2;
	}
	sort( arr, arr + n );

	int last_pos = arr[ 0 ] - 1 + l;
	int count = 1;
	for ( int i = 1; i < n; ++i )
	{
		if ( arr[ i ] + 1 > last_pos )
		{
			last_pos = arr[ i ] - 1 + l;
			++count;
		}
	}

	cout << count;
}