#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void AddIfDontExist( set<string> stops, map<set<string>, int>& buses )
{
    if (buses.count(stops) == 0) {

      const int new_number = buses.size() + 1;
      buses[stops] = new_number;
      cout << "New bus " << new_number << endl;
      
    } else {
      cout << "Already exists for " << buses[stops] << endl;
    }
}

int
main()
{
    int input_num;
    cin >> input_num;
    map<set<string>, int> buses;

    for(int i = 0; i < input_num; ++i)
    {
        int num;
        cin >> num;
        set<string> temp;

        for (int j = 0; j < num; ++j)
        {
            string stop;
            cin >> stop;
            temp.insert(stop);
        }

        AddIfDontExist( temp, buses );
        
    }
    return 0;
}
