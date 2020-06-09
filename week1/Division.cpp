#include <iostream>
using namespace std;

int 
main()
{
    int a, b, res;
    cin >> a >> b;

    if (b != 0)
    {
        cout << a / b;
    }
    else 
    {
        cout << "Impossible";
    }
    return 0;
}