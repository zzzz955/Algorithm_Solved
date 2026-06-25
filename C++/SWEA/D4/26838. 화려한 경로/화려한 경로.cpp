#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 1;
const int M = 1 << 5;

int colors[ N ];
vector<int> edges[ N ];
int n, m, k;

long long dp[ M ][ N ];
int v[ M ][ N ];
int t;

void Init()
{
    cin >> n >> m >> k;
    for ( int i = 1; i <= n; ++i )
    {
        cin >> colors[ i ];
        edges[ i ].clear();
    }

    while ( m-- )
    {
        int f, t; cin >> f >> t;
        edges[ f ].push_back( t );
        edges[ t ].push_back( f );
    }

    // 새 테스트케이스마다 방문값을 올림
    ++t;
}

// mask = 지금까지 쓴 색 집합 (color[cn] 포함)
// cn에서 시작하는 (정점 1개 이상) 유효 경로 수
long long DFS( int cn, int mask )
{
    // 이미 방문한 케이스
    if ( v[ mask ][ cn ] == t ) 
        return dp[ mask ][ cn ];

    // 방문 처리
    v[ mask ][ cn ] = t;

    long long res = 1;
    for ( int nn : edges[ cn ] )
    {
        int cbit = 1 << ( colors[ nn ] - 1 );

        // 이미 방문한 색인지 여부 확인
        if ( mask & cbit ) 
            continue;

        res += DFS( nn, mask | cbit );
    }
    return dp[ mask ][ cn ] = res;
}

int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    int tc; cin >> tc;
    while ( tc-- )
    {
        Init();
        long long ans = 0;
        for ( int s = 1; s <= n; ++s )
            // color를 0-based-indexing화
            // 정점 1개짜리 제외
            ans += DFS( s, 1 << ( colors[ s ] - 1 ) ) - 1;
        cout << ans << "\n";
    }
}