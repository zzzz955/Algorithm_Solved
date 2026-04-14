#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	cin >> n >> q;
	vector< int > backward, forward;
	int cur = 0;
	while ( q-- )
	{
		char c; cin >> c;
		if ( c == 'B' )
		{
			if ( !backward.empty() )
			{
				forward.push_back( cur );
				cur = backward.back();
				backward.pop_back();
			}
		}
		else if ( c == 'F' )
		{
			if ( !forward.empty() )
			{
				backward.push_back( cur );
				cur = forward.back();
				forward.pop_back();
			}
		}
		else if ( c == 'A' )
		{
			int next; cin >> next;
			forward.clear();

			if ( cur )
				backward.push_back( cur );

			cur = next;
		}
		else
		{
			backward.erase( 
				unique( backward.begin(), backward.end() ), 
				backward.end() );
		}
	}

	cout << cur << '\n';
	if ( backward.empty() )
	{
		cout << -1;
	}
	else
	{
		while ( !backward.empty() )
		{
			int back = backward.back();
			backward.pop_back();
			cout << back;

			if ( !backward.empty() )
				cout << " ";
		}
	}
	cout << '\n';

	if ( forward.empty() )
	{
		cout << -1;
	}
	else
	{
		while ( !forward.empty() )
		{
			int back = forward.back();
			forward.pop_back();
			cout << back;
			
			if ( !forward.empty() )
				cout << " ";
		}
	}
}