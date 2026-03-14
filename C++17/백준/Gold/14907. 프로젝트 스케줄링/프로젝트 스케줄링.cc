#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

const int N = 26;
unordered_map< char, int > cnt;
unordered_map< char, int > weights;
unordered_map< char, int > pre_sum;
unordered_map< char, vector< char > > edges;

vector< string > Split(const string& s)
{
	stringstream ss( s );
	vector< string > args;
	string temp = "";
	
	while ( getline( ss, temp, ' ' ) )
		args.push_back( temp );

	return args;
}

void ParsingAndInitialize(const string& s)
{
	vector< string > args = Split( s );
	char node = args[ 0 ][ 0 ];
	weights[ node ] = stoi( args[ 1 ] );
	string conn = args.size() > 2 ? args[ 2 ] : "";
	if ( !cnt.count( node ) )
		cnt[ node ] = 0;

	for ( int i = 0; i < ( int )conn.size(); ++i )
	{
		char nextNode = conn[ i ];
		edges[ nextNode ].push_back( node );
		++cnt[ node ];
	}
}

void Input()
{
	string s;
	while ( getline( cin, s ) )
	{
		if ( s.empty() )
			break;

		ParsingAndInitialize( s );
	}
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	Input();

	int mx = 0;
	queue< char > q;
	for ( const auto& [k, v] : cnt )
	{
		//cout << k << " " << v << "\n";
		if ( !v )
		{
			q.push( k );
			pre_sum[ k ] = weights[ k ];
		}
	}

	while ( !q.empty() )
	{
		char node = q.front(); q.pop();
		//cout << node << " " << pre_sum[ node ] << "\n";
		mx = max( mx, pre_sum[ node ] );

		for ( const char& nextNode : edges[ node ] )
		{
			pre_sum[ nextNode ] = max( pre_sum[ nextNode ], pre_sum[ node ] + weights[ nextNode ] );
			if ( !--cnt[ nextNode ] )
				q.push( nextNode );
		}
	}

	cout << mx;
}