/*
Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string> и возвращающую множество значений этого словаря:
*/
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

set<string> BuildMapValueSet( const map<int, string> m )
{
    set<string> s;
    for ( const auto i : m )
    {
        s.insert( i.second );
    }
    return s;
}

void PrintSet( const set<string>& s )
{
    cout << "Size = " << s.size() << endl;
    for ( const auto a : s )
    {
        cout << a << endl;
    }
}

int 
main(int argc, char const *argv[])
{
    map<int, string> m;

    m[1] = "f";
    m[2] = "s";
    m[3] = "f";
    m[4] = "f";
    m[5] = "f";
    m[6] = "s";
    set<string> s = BuildMapValueSet( m );
    PrintSet(s);
    
    return 0;
}
