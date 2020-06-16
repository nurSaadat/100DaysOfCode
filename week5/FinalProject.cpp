#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;

struct Day
{
    int value;
    explicit Day(const int& new_val)
    {
        value = new_val;
    }
};

struct Month
{
    int value;
    explicit Month(const int& new_val)
    {
        value = new_val;
    }
};

struct Year
{
    int value;
    explicit Year(const int& new_val)
    {
        value = new_val;
    }
};

class Date 
{
    public:
        Date(Year y, Month m, Day d) 
        {
            day = d.value;
            month = m.value;
            year = y.value;
        }
        int GetYear() const
        {
            return year;
        }
        int GetMonth() const
        {
            return month;
        }
        int GetDay() const
        {
            return day;
        }
    private:
        int day;
        int month;
        int year;
};

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() == rhs.GetMonth())
        {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

class Database
{
    public:
        void AddEvent(const Date& date, const string& event)
        {
            date_events[date].insert(event);
        }

        bool DeleteEvent(const Date& date, const string& event)
        {
            if (date_events[date].count(event) != 0)
            {
                date_events[date].erase(event);
                cout << "Deleted successfully";
            }
            else
            {
                cout << "Event not found";
            }            
        }

        int  DeleteDate(const Date& date)
        {
            int n = date_events[date].size();
            date_events.erase(date);
            cout << "Deleted " << n << " events";
        }

        void Find(const Date& date) const
        {
            try
            {
                set<string> events = date_events.at(date);
                for (const auto& event : events)
                {
                    cout << event << endl;
                }
            }
            catch(const out_of_range& e)
            {}
        }

        void Print() const
        {
            for (const auto& event : date_events)
            {
                for (const string& str : event.second)
                {
                    cout << setw(4) << setfill('0') << event.first.GetYear() << 
                            setw(2) << setfill('0') << event.first.GetMonth() <<
                            setw(2) << setfill('0') << event.first.GetDay() <<
                            " " << str << endl;
                }
            }
        }
    private:
        map<Date, set<string>> date_events;
};

bool HandleDateEntry(Date& date)
{
    
    int d, m, y;
    return false;
}

int main() {
    Database db;

    string command;
    while (getline(cin, command)) 
    {
        string command;
        cin >> command;
        Date date;
        if (command == "Add")
        {
            if (HandleDateEntry(date))
            {

            }
        }
        else if (command == "Del")
        {
            if (HandleDateEntry(date))
            {
                
            }
        }
        else if (command == "Find")
        {
            if (HandleDateEntry(date))
            {
                
            }
        }
        else if (command == "Print")
        {

        }
        else if (command.size() == 0)
        {
            continue;
        }
        else
        {
            cout << "Unknown command: " << command << endl;
        }
    }

    return 0;
}