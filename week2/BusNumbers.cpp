#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 
 // проверяем, не существует ли уже маршрут с таким набором остановок
    if (buses.count(stops) == 0) {
      
      // если не существует, нужно сохранить новый маршрут;
      // его номер на единицу больше текущего количества маршрутов
      const int new_number = buses.size() + 1;
      buses[stops] = new_number;
      cout << "New bus " << new_number << endl;
      
    } else {
      cout << "Already exists for " << buses[stops] << endl;
    }
*/

void AddIfDontExist( vector<string> stops, map<vector<string>, int>& m)
{
    for (auto b : m)
    {
        if ( b.first == stops )
        {
            cout << "Already exists for " << b.second << endl;
            return;
        }
    }
    int bus_num = m.size() + 1;
    m[stops] = bus_num;
    cout << "New bus " << bus_num << endl;
}

int
main()
{
    int input_num;
    cin >> input_num;
    map<vector<string>, int> stops_for_buses;

    for(int i = 0; i < input_num; ++i)
    {
        int num;
        cin >> num;
        vector<string> temp;

        for (int j = 0; j < num; ++j)
        {
            string stop;
            cin >> stop;
            temp.push_back(stop);
        }

        AddIfDontExist( temp, stops_for_buses );
        
    }
    return 0;
}
