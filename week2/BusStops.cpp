#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void NewBus(map<string, vector<string>>& b_to_s, map<string, vector<string>>& s_to_b);
void BusesForStop(map<string, vector<string>>& s_to_b);
void StopsForBus(map<string, vector<string>>& b_to_s, map<string, vector<string>>& s_to_b);
void AllBuses(map<string, vector<string>>& b_to_s);

int
main()
{
    int input_num;
    cin >> input_num;
    map<string, vector<string>> buses_for_stops;
    map<string, vector<string>> stops_for_buses;

    for(int i = 0; i < input_num; ++i)
    {
        string command;
        cin >> command;
        if (command == "NEW_BUS")
            NewBus(buses_for_stops, stops_for_buses);
        if (command == "BUSES_FOR_STOP")
            BusesForStop(stops_for_buses);
        if (command == "STOPS_FOR_BUS")
            StopsForBus(buses_for_stops, stops_for_buses);
        if (command == "ALL_BUSES")
            AllBuses(buses_for_stops);
    }
    return 0;
}

void NewBus(map<string, vector<string>>& b_to_s, map<string, vector<string>>& s_to_b)
{
    string bus;
    int stop_count;
    cin >> bus >> stop_count;

    for (int i = 0; i < stop_count; ++i)
    {
        string stop;
        cin >> stop;
        b_to_s[bus].push_back(stop);
        s_to_b[stop].push_back(bus);
    }
}

void BusesForStop(map<string, vector<string>>& s_to_b)
{
    string stop;
    cin >> stop;

    if (s_to_b.count(stop) != 0)
    {
        for (auto bus : s_to_b[stop])
        {
            cout << bus << " ";
        }
    }
    else
    {
        cout << "No stop";
    }       

    cout << endl;
}

void StopsForBus(map<string, vector<string>>& b_to_s, map<string, vector<string>>& s_to_b)
{
    string bus;
    cin >> bus;

    if (b_to_s.count(bus) != 0)
    {
        for (const auto& stop : b_to_s[bus])
        {
            cout << "Stop " << stop << ": ";

            if (s_to_b[stop].size() != 1)
            {
                for (const auto& b : s_to_b[stop])
                {
                    if (b != bus)
                    {
                        cout << b << " ";
                    }
                }
            }
            else 
            {
                cout << "no interchange";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No bus" << endl; 
    }
}

void AllBuses(map<string, vector<string>>& b_to_s)
{
    if (b_to_s.size() != 0)
    {
        for (auto bus : b_to_s)
        {
            cout << "Bus " << bus.first << ": ";
            for (auto stop : bus.second)
            {
                cout << stop << " "; 
            }
            cout << endl; 
        }
    }
    else
    {
        cout << "No buses" << endl;
    }
}
