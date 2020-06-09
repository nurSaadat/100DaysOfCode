#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> BuildCharCounters( const string& a)
{
    map<char, int> counters;
    for ( const auto& ch : a )
        counters[ch]++;
    
    return counters;

}

int
main()
{
    int input_num;
    cin >> input_num;
    for ( int i = 0; i < input_num; ++i )
    {
        string first, second;
        cin >> first >> second;
        map<char, int> dict1 = BuildCharCounters( first );
        map<char, int> dict2 = BuildCharCounters( second );
        if ( dict1 == dict2 )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }
    return 0;
}