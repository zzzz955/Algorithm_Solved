#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 100;
int t, n;
int arr[ N * ( N - 1 ) / 2 ];

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> t;
	while ( t-- )
	{
		cin >> n;
		for ( int i = 0; i < n * ( n - 1 ) / 2; ++i )
			cin >> arr[ i ];

		sort( arr, arr + n * ( n - 1 ) / 2 );
		ll min_value = 0;
		ll max_value = 0;
		int index = 0;

		for ( int i = 0; i < n - 1; ++i )
		{
			min_value += arr[ i ];
			max_value += arr[ index + i ];
			index = index + i;
		}
			
		cout << min_value << " " << max_value << '\n';
	}
}