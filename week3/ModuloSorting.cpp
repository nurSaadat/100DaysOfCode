#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int
main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), [](int x, int y)
    {
        return(abs(x) < abs(y));
    });

    for ( const auto& i : v )
    {
        cout << i << " ";
    }
    cout << endl;
}