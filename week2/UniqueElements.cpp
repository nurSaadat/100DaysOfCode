#include <iostream>
#include <string>
#include <set>
using namespace std;

int 
main()
{
    int n;
    cin >> n;
    set<string> s;

    for ( int i = 0; i < n; i++ )
    {
        string temp;
        cin >> temp;
        s.insert( temp );
    }

    cout << s.size() << endl;
}