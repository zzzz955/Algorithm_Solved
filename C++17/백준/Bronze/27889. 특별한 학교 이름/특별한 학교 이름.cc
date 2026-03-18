#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map< string, string > dic;
	dic[ "NLCS" ]	 = "North London Collegiate School";
	dic[ "BHA" ]	 = "Branksome Hall Asia";
	dic[ "KIS" ]	 = "Korea International School";
	dic[ "SJA" ]	 = "St. Johnsbury Academy";
	
	string s; cin >> s;
	cout << dic[ s ];
}