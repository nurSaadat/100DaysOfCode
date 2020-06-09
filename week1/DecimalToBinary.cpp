#include <iostream>
#include <vector>
using namespace std;

int
main()
{
    int n, k;
    vector<int> repr;
    cin >> n;

    while ( n > 1 )
    {
        k = n % 2;
        repr.push_back(k);
        n /= 2;        
    }
    if ( n == 1 )
        repr.push_back(n);

    for (int i = repr.size() - 1; i >= 0; --i)
    {
        cout << repr[i];
    }
    return 0;
}