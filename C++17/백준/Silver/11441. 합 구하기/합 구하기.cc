#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int pre_sum[ N + 1 ];

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> n;
	for ( int i = 0; i < n; ++i )
	{
		int d; cin >> d;
		pre_sum[ i + 1 ] = pre_sum[ i ] + d;
	}
		

	cin >> m;
	while ( m-- )
	{
		int i, j;
		cin >> i >> j;
		cout << pre_sum[ j ] - pre_sum[ i - 1 ] << '\n';
	}
}