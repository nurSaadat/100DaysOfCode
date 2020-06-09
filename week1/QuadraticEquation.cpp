#include <iostream>
#include <cmath>
using namespace std;

int 
main()
{
    double a, b, c;
    double root, disc;
    double x1, x2;

    /* Take input three arguments */
    cin >> a >> b >> c;

    /* Calculate discriminant */
    disc = b * b - 4 * a * c;
    root = sqrt(disc);

    /* Take care of linear case */
    if (a == 0 && b != 0)
        cout << -c / b;
    else 
    {
        /* If real root exists, output */
        if ( root == root && a != 0)
        {
            x1 = (-b + root) / (2 * a);
            x2 = (-b - root) / (2 * a);
            if ( x1 == x1 )
                cout << x1 << " ";
            if ( x2 == x2 && x1 != x2 )
                cout << x2;
        }
    }
    
    return 0;
        
}