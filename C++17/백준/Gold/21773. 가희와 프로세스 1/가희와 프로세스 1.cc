#include <iostream>
#include <queue>
using namespace std;

int t, n;
struct Process
{
	int id, time, priority;
	bool operator<( const Process& other ) const
	{
		if ( priority == other.priority )
			return id > other.id;

		return priority < other.priority;
	}
};

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> t >> n;
	priority_queue< Process > pq;
	while ( n-- )
	{
		int a, b, c; cin >> a >> b >> c;
		pq.push( { a, b, c } );
	}

	while ( t-- )
	{
		Process process = pq.top(); pq.pop();
		int id = process.id, time = process.time, priority = process.priority;
		cout << id << '\n';
		if ( --time )
			pq.push( { id, time, priority - 1 } );
	}
}