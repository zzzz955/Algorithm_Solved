#include <iostream>
using namespace std;

const int N = 13;
int n, x, y, uc, ans;
bool used[ N ];
int arr[ N * 2 ];

void bt( int level )
{
	if ( level > 2 * n )
		return;

	for ( int i = 1; i <= n; ++i )
	{
		if ( used[ i ] )
			continue;

		if ( level + i + 1 > 2 * n )
			continue;

		if ( arr[ level + i + 1 ] )
			continue;

		used[ i ] = true;
		arr[ level ] = i;
		arr[ level + i + 1 ] = i;
		++uc;
		if ( uc != n )
		{
			for ( int j = level + 1; j <= 2 * n; ++j )
			{
				if ( !arr[ j ] )
				{
					bt( j );
					break;
				}
			}
		}
		else ++ans;
		--uc;
		arr[ level + i + 1 ] = 0;
		arr[ level ] = 0;
		used[ i ] = false;
	}
}

int main()
{
	cin >> n >> x >> y;

	int diff = y - x - 1;
	used[ diff ] = true;
	arr[ x ] = diff;
	arr[ y ] = diff;
	++uc;

	bt( x == 1 ? 2 : 1 );
	cout << ans;
}