#include <iostream>
using namespace std;

int 
main()
{
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    
    if (n > a && n > b)
    {
        cout << (n * (100 - y)) / 100;
    } 
    else 
    {
        if (n > a)
        {
            cout << (n * (100 - x)) / 100;
        }
        else 
        {
            cout << n;
        }        
    }

    return 0;
}