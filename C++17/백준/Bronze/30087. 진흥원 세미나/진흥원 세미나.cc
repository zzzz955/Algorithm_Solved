#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	unordered_map< string, string > dic;
	dic[ "Algorithm"				 ] = "204";
	dic[ "DataAnalysis"				 ] = "207";
	dic[ "ArtificialIntelligence"	 ] = "302";
	dic[ "CyberSecurity"			 ] = "B101";
	dic[ "Network"					 ] = "303";
	dic[ "Startup"					 ] = "501";
	dic[ "TestStrategy"				 ] = "105";

	int n; cin >> n;
	for ( int i = 0; i < n; ++i )
	{
		string s; cin >> s;
		cout << dic[ s ] << '\n';
	}
}