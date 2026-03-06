#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue< int, vector< int >, greater< int > > pq;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n;
	for ( int i = 0; i < n; ++i )
	{
		int l; cin >> l;
		pq.push( l );
	}

	long long ans = 0;
	while ( pq.size() > 1 )
	{
		int s1 = pq.top(); pq.pop();
		int s2 = pq.top(); pq.pop();
		int sum = s1 + s2;
		ans += s1 + s2;
		pq.push( s1 + s2 );
	}

	cout << ans;
}