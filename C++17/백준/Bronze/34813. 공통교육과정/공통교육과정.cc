#include <iostream>
using namespace std;

int main()
{
	char c; cin >> c;
	switch ( c )
	{
	case 'F' :
		cout << "Foundation";
		break;
	case 'C' :
		cout << "Claves";
		break;
	case 'V':
		cout << "Veritas";
		break;
	default:
		cout << "Exploration";
		break;
	}
}