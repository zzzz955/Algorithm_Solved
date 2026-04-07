#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if ( a + c > b + d )
		cout << "Yongdap";
	else if ( a + c < b + d )
		cout << "Hanyang Univ.";
	else
		cout << "Either";
}