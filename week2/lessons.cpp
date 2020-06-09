/* Sets */
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void PrintSet( const set<string>& s )
{
    cout << "Size = " << s.size() << endl;
    for ( const auto a : s )
    {
        cout << a << endl;
    }
}

int
main()
{
    vector<string> v = {"a", "b", "c", "a"};
    set<string> s (begin(v), end(v));
    PrintSet(s);
    s.erase("d");
    PrintSet(s);
}

/* Maps */
// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// using namespace std;

// void PrintMap(const map<string, int>& m)
// {
//     cout << "Size = " << m.size() << endl;
//     for (const auto& item : m)
//     {
//         cout << item.first << " : " << item.second << endl;
//     }
// }

// int 
// main()
// {
//     /* You can store map values like that */
//     map<int, string> events;
//     events[1950] = "Bjarne Stroustrup's birth";
//     events[1941] = "Dennis Ritchie's birth";
//     /* Or like that */
//     map<string, int> nums = {{"one", 1}, {"two", 2}, {"three", 3}};

//     /* Delete */
//     events.erase(1941);

//     /* Count num of occurences */
//     vector<string> words = {"one", "two", "one"};
//     map<string, int> counters;
//     for (const string& word : words)
//     {
//         /* No need to check for existence */
//         ++counters[word];
//     }
//     // PrintMap(counters);

//     /* Group by first letter */
//     words = {"one", "two", "three"};
//     map<char, vector<string>> grouped;
//     for (const string& word : words)
//     {
//         grouped[word[0]].push_back( word );
//     }
//     for (const auto& item : grouped)
//     {
//         cout << item.first << " : ";
//         for (const string& s : item.second)
//         {
//             cout << s << ", ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


/* Lesson 2 */ 
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// void PrintVector( const vector<string>& v )
// {
//     for ( string s : v )
//         cout << s << endl;
// }

// int
// main()
// {
//     int n;
//     cin >> n;

//     /* Vector constructor */
//     vector<string> v1(n);
//     /* If you initialized with some size n, then the size will always be the same */

//     /* Read elements into vector*/
//     for ( string& s : v1 )
//     {
//         cin >> s;
//         cout << "Vector 1 size is " << v1.size() << endl;
//     }
//     /* Print vector */
//     PrintVector(v1);

//     /* Another example with varying size */
//     vector<string> v2;
//     int i = 0;
//     string temp;
//     while (i < n)
//     {
//         cin >> temp;
//         v2.push_back(temp);
//         cout << "Vector 2 size is " << v2.size() << endl;
//         i++;
//     } 
//     /* Print vector */
//     PrintVector(v2);

//      /* You can fill the vector by some values */
//     vector<bool> is_holiday (28, false);

//     return 0;
// }

/* Lesson 1 */
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// void Sort( vector<int>& v )
// {
//     sort( begin(v), end(v) );
// }

// void Swap( int& x, int& y )
// {
//     int temp = x;
//     x = y;
//     y = temp;
// }

// int 
// main()
// {
//     int a = 1, b = 2;
//     Swap( a, b );
//     cout << a << " " << b << endl;
//     vector<int> nums = {1, 3, 4, 7, 2, 9, 0};
//     Sort( nums );
//     for ( auto n : nums )
//     {
//         cout << n << " ";
//     }
//     return 0;
// }
