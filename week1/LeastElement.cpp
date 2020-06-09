#include <iostream>
#include <string>
using namespace std;

int 
main()
{
    string a, b, c;
    cin >> a >> b >> c;
    string less;
    if (a < b)
        less = a;
    else 
        less = b;
    
    if (c < less)
        cout << c;
    else 
        cout << less;

    return 0;
}