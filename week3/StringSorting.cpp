#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int
main()
{
    int n;
    cin >> n;
    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), [](string x, string y)
    {
        for (auto& c : x)
        {
            c = (char)tolower(c);
        }
        for (auto& c : y)
        {
            c = (char)tolower(c);
        }
        return (x < y);
    });

    /* Alternative sort */
    // sort(begin(v), end(v), 
    //     [](const string& x, const string& y)
    //     {
    //         return lexicographical_compare(
    //             begin(x), end(x),
    //             begin(y), end(y), 
    //             [](char cl, char cr)
    //             {
    //                 return(tolower(cl) < tolower(cr));
    //             }
    //         );
    //     }
    // );

    for ( const auto& i : v )
    {
        cout << i << " ";
    }
    cout << endl;
}