#include <iostream>
#include <string>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int t;
string s;

int main()
{
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		cin >> s;
		int len = s.size();
		int mn = 2e9;
		vector< pii > splits;
		for ( int i = 1; i < len; ++i )
		{
			int front = stoi( string( s, 0, i ) );
			int back = stoi( string( s, i, len ) );
			mn = min( mn, front + back );
			//cout << front << " " << back << " " << mn << '\n';
		}
		cout << "#" << tc << " " << mn << '\n';
	}
}