#include <string>
#include <set>
#include <iostream>
#include <map>
using namespace std;

void Add( map<string, set<string>>& dict );
void Count( map<string, set<string>>& dict );
void Check( map<string, set<string>>& dict );

int
main()
{
    int n;
    cin >> n;
    map<string, set<string>> synonims;

    for ( int i = 0; i < n; i++ )
    {
        string command; 
        cin >> command;

        if ( command == "ADD" )
        {
            Add( synonims );
        }
        else if ( command == "COUNT" )
        {
            Count( synonims );
        }
        else if ( command == "CHECK" )
        {
            Check( synonims );
        }
    }
}

void Add( map<string, set<string>>& dict )
{
    string word1, word2;
    cin >> word1 >> word2;

    dict[word1].insert(word2);
    dict[word2].insert(word1);
}

void Count( map<string, set<string>>& dict )
{
    string word1;
    cin >> word1;

    cout << dict[word1].size() << endl;
}

void Check( map<string, set<string>>& dict )
{
    string word1, word2;
    cin >> word1 >> word2;

    if ( dict.count(word1) != 0 )
    {
        if ( dict[word1].count(word2) != 0)
        {
            cout << "YES" << endl;
            return;
        }

    } 

    cout << "NO" << endl;
}
