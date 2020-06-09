// /* Lesson 5 */
// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
// using namespace std;

// int
// main()
// {
//     /* Return sum of ints */
//     vector <int> a = {1, 3, 5, 6, 7, 8};
//     int sum = 0;
//     for (auto i : a)
//     {
//         sum += i;
//     }
//     cout << sum << endl;

//     /* Retrun sum of numbers and concatenation of strings */
//     map<string, int> b = {{"a", 1}, {"b", 2}, {"c", 3}};

//     sum = 0;
//     string concat;
//     for (auto i : b)
//     {
//         concat += i.first;
//         sum += i.second;
//     }
//     cout << sum << " " << concat << endl;

//     /* Return position of a */
//     string c = "asdfasdfasdfasdf";
//     int idx = 0;
//     for (auto i : c)
//     {
//         if (i == 'a')
//         {
//             cout << idx << endl;
//         }
//         ++idx;
//     }

//     for (int i = 0; i < c.size(); ++i)
//     {
//         if (c[i] == 'a')
//         {
//             cout << i << endl;
//             break;
//         }
//     }

//     return 0;
// }

// /* Lesson 4 */
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int 
// main()
// {
//     /* You can use specific types for counters */
//     string s = "abcdef";
//     for ( char c : s )
//     {
//         cout << c << ", ";
//     }

//     /* But it is easier to use auto */
//     vector<string> grades = {"1", "2", "3", "4", "5 +" };
//     for ( auto c : grades )
//     {
//         cout << c << ", ";
//     }

//     /* You can count like this */
//     vector<int> nums = {1, 3, 4, 5, 3, 6, 3};
//     int ncount = 0;
//     for ( auto n : nums )
//     {
//         if ( n == 3 )
//             ncount ++;
//     }
//     cout << "There is " << ncount << " threes\n";

//     /* Or include algorithms and do it like this */
//     int quantity = count( begin( nums ), end ( nums ), 3 );
//     cout << "There is " << quantity << " threes\n";

//     sort( begin( nums ), end( nums ) );
//     for (auto n : nums)
//         cout << n << ", ";

//     return 0;
// }

/* Lesson 3 */
/* Strings can be compared */
/* Arrays can be compared */

/* Lesson 2 */
/* Data types */
// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// using namespace std;

// struct Person 
// {
//     string name;
//     string surname;
//     int age;
// };

// int 
// main()
// {
//     int a = 0;
//     double b = 1.2;
//     bool c = true;
//     char d = 'd';

//     /* Needs a library */
//     string e = "efgh";

//     /* Needs a library */
//     vector<int> nums = {1, 3, 5, 7};
//     cout << nums.size() << "\n";

//     /* Needs a library */
//     map<string, int> name_to_val;
//     name_to_val["one"] = 1;
//     name_to_val["two"] = 2;
//     cout << "two is " << name_to_val["two"] << "\n";

//     /* Custom types */
//     vector<Person> stuff;
//     stuff.push_back({"Ivan", "Ivanov", 25});
//     stuff.push_back({"Petr", "Petrov", 25});
//     cout << stuff[0].name << "\n";
//     return 0;
// }


/* Lesson 1 */
/* Hello World */
// #include <iostream>
// using namespace std;

// int 
// main()
// {
//     cout << "Hello, world";
//     return 0;
// }