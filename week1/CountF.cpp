#include <iostream>
#include <string>
using namespace std;

int 
main()
{
    string f;
    cin >> f;

    int result = -2;

    for (int i = 0; i < f.size(); ++i)
    {
        if (f[i] == 'f')
        {
            if (result == -2)
            {
                result = -1;
            }
            else if (result == -1)
            {
                result == i;
                break;
            }
        }
    }
    cout << result;
    return 0;
}

// int 
// main ()
// {
//     string a;
//     cin >> a;

//     int count = 0;
//     for (int i = 0; i < a.size(); ++i)
//     {
//         if (a[i] == 'f')
//         {
//             count++;
//         }
//         if (count == 2)
//         {
//             cout << i;
//             break;
//         }
//     }

//     if (count == 1)
//     {
//         cout << -1;
//     }
//     if (count == 0)
//     {
//         cout << -2;
//     }


//     return 0;
// }