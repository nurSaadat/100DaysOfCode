#include <iostream>
#include <string>
#include <map>
using namespace std;

void ChangeCapital( map<string, string>& m );
void Rename( map<string, string>& m );
void About( map<string, string>& m );
void Dump( map<string, string>& m );

int
main()
{
    int inputs_num;
    cin >> inputs_num;
    map<string, string> country_with_capital;

    for ( int i = 0; i < inputs_num; ++i )
    {
        string command;
        cin >> command;
        if ( command == "CHANGE_CAPITAL" )
            ChangeCapital( country_with_capital );
        if ( command == "RENAME" )
            Rename( country_with_capital );
        if ( command == "ABOUT" )
            About( country_with_capital );
        if ( command == "DUMP" )
            Dump( country_with_capital );
    }
    return 0;
}

void ChangeCapital( map<string, string>& m )
{
    string country, new_capital;
    cin >> country >> new_capital;

    if ( m.count(country) != 0 )
    {
        if (m[country] == new_capital)
        {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        }
        else 
        {
            cout << "Country " << country << " has changed its capital from "
            << m[country] << " to " << new_capital << endl;
            m[country] = new_capital;
        }
    }
    else
    {
        m[country] = new_capital;
        cout << "Introduce new country " << country << " with capital "  << new_capital << endl;
    }
}

void Rename( map<string, string>& m )
{
    string old_country_name, new_country_name;
    cin >> old_country_name >> new_country_name;

    if ( m.count(old_country_name) == 0 || old_country_name == new_country_name || m.count(new_country_name) != 0 )
    {
        cout << "Incorrect rename, skip" << endl;
        return;
    }
    else 
    {
        cout << "Country " << old_country_name << " with capital " << 
        m[old_country_name] << " has been renamed to " << new_country_name << endl;
        
        m[new_country_name] = m[old_country_name];
        m.erase( old_country_name );
    }
}

void About( map<string, string>& m )
{
    string country;
    cin >> country;

    if ( m.count(country) == 0 )
        cout << "Country " << country << " doesn't exist" << endl;
    else
        cout << "Country " << country << " has capital " << m[country] << endl;
}

void Dump( map<string, string>& m )
{
    if (m.size() == 0)
    {
        cout << "There are no countries in the world" << endl;
    }
    else 
    {
        for (const auto& item : m)
        {
            cout << item.first << "/" << item.second << " ";
        }
        cout << endl;
    }
}


