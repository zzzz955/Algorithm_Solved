#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    int T;
    cin >> T;

    while ( T-- )
    {
        string A;
        cin >> A;

        bool hasN = false, hasS = false, hasE = false, hasW = false;

        for ( char c : A )
        {
            if ( c == 'N' ) hasN = true;
            else if ( c == 'S' ) hasS = true;
            else if ( c == 'E' ) hasE = true;
            else if ( c == 'W' ) hasW = true;
        }

        if ( ( hasN == hasS ) && ( hasE == hasW ) )
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}