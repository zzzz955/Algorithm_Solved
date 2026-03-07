#include <iostream>
using namespace std;

int main()
{
	int n;  cin >> n;
	int cur = 0;
	for ( int i = 0; i < n; ++i )
	{
		int d; cin >> d;
		cur += d;
	}

	if ( cur < 0 )
		cout << "Left";
	else if ( cur == 0 )
		cout << "Stay";
	else
		cout << "Right";
}