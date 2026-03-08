#include <iostream>
#include <queue>
using namespace std;

const int N = 50;
int n, m;
uint8_t A[ N ][ N ];
uint8_t B[ N ][ N ];
bool v[ N ][ N ];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos
{
	int x, y;
};

void Input()
{
	cin >> n >> m;
	for ( int i = 0; i < n; ++i )
	{
		for ( int j = 0; j < m; ++j )
		{
			cin >> A[ i ][ j ];
		}
	}

	for ( int i = 0; i < n; ++i )
	{
		for ( int j = 0; j < m; ++j )
		{
			cin >> B[ i ][ j ];
		}
	}
}

void FloodFill( int sx, int sy, uint8_t prev, uint8_t next )
{
	queue<Pos> q;
	q.push( { sx, sy } );
	v[ sx ][ sy ] = true;
	A[ sx ][ sy ] = next;

	while ( !q.empty() )
	{
		auto [cx, cy] = q.front(); q.pop();

		for ( int i = 0; i < 4; ++i )
		{
			int nx = cx + dx[ i ], ny = cy + dy[ i ];

			if ( 0 <= nx && nx < n && 0 <= ny && ny < m && !v[ nx ][ ny ] && A[ nx ][ ny ] == prev )
			{
				v[ nx ][ ny ] = true;
				A[ nx ][ ny ] = next;
				q.push( { nx, ny } );
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	Input();
	bool flag = true;
	for ( int i = 0; i < n; ++i )
	{
		if ( !flag )
			break;

		for ( int j = 0; j < m; ++j )
		{
			if ( v[ i ][ j ] )
			{
				if ( A[ i ][ j ] != B[ i ][ j ] )
				{
					flag = false;
					break;
				}
				continue;
			}
			
			FloodFill( i, j, A[ i ][ j ], B[ i ][ j ] );
		}
	}

	cout << ( flag ? "YES" : "NO" );
}