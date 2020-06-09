#include <iostream>
using namespace std;

int Factorial( int x )
{
    int fact = 1;
    while (x > 0)
    {
        fact *= x;
        --x;
    }
    return fact;
}

int
main()
{
    int a;
    cin >> a;
    a = Factorial(a);
    cout << a;
    return 0;
}