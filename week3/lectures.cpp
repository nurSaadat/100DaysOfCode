#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/* Functions */
// bool Gt2(int x)
// {
//     if (x > 2)
//     {
//         return true;
//     }
//     return false;
// }

// void PrintVector(const vector<int>& v, const string& title)
// {
//     cout << title << ": ";
//     for (const auto& e : v)
//     {
//         cout << e << " ";
//     }
//     cout << endl;
// }

// int
// main()
// {
//     cout << "min of 2 and 3: " << min(2, 3) << endl;
//     cout << "max of 2 and 3: " << max(2, 3) << endl;
//     vector<int> v {
//         1, 3, 2, 4, 5, 2
//     };
//     PrintVector(v , "init");
//     sort(begin(v), end(v));
//     PrintVector(v , "sort");

//     cout << "count 2: " << count(begin(v), end(v), 2) << endl;
//     /* Count if */
//     cout << "count greater than 2: " << count_if(begin(v), end(v), Gt2) << endl;
//     /* Lambda function with Custom threshold */
//     int thr;
//     cin >> thr;
//     cout << "count less than " << thr << ": " << count_if(begin(v), end(v), [thr](int x){
//         if (x < thr)
//         {
//             return true;
//         }
//         return false;
//     }) << endl;

//     /* Modifying range-base for */
//     for (auto& i : v)
//     {
//         ++i;
//     }
//     PrintVector(v, "incr");
// }