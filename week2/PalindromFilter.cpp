#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom( string s )
{
    if ( s == "" )
        return true;

    for ( int i = 0; i < s.size() / 2; ++i )
    {
        if ( s[i] != s[s.size() - 1 - i] )
            return false;
    }

    return true;

}

vector<string> PalindromFilter( vector<string> words, int minLength )
{
    vector<string> satisfies;
    for ( auto w : words )
    {
        if ( w.size() >= minLength && IsPalindrom( w ) )
        {
            satisfies.push_back(w);
        }
    }
    return satisfies;
}

int
main()
{
    return 0;
}