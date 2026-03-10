#include <iostream>
#include <map>
using namespace std;

int n;
map< int, int > dic;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n;
	while ( n-- )
	{
		int op, v; cin >> op >> v;
		if ( op == 1 )
			++dic[ v ];
		
		if ( op == 2 )
		{
			if ( dic.empty() )
				continue;

			int b = dic.rbegin()->first;
			int t = max( b - v, 0 );
			if ( t == 0 )
			{
				dic.clear();
				continue;
			}

			auto it = dic.upper_bound( t );
			int cnt = 0;
			while ( it != dic.end() )
			{
				cnt += it->second;
				it = dic.erase( it );
			}

			dic[ t ] += cnt;
		}
	}

	long long sum = 0;
	for ( const auto& [k, v] : dic )
		sum += ( long long )k * v;

	cout << sum;
}