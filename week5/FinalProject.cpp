#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;

class Date 
{
    public:
        Date ()
        {
            year = 1;
            month = 1;
            day = 1;
        }
        Date(int y, int m, int d)
        {
            year = y;

            /* Check month */
            if (m < 1 || m > 12)
            {
                stringstream ss;
                ss << "Month value is invalid: " << m;
                throw invalid_argument(ss.str());
            }
            month = m;
            
            /* Check day */
            if (d < 1 || d > 31)
            {
                stringstream ss;
                ss << "Day value is invalid: " << d;
                throw invalid_argument(ss.str());
            }
            day = d;
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

istream& operator>>(istream& s, Date& date)
{
    string date_str;
    s >> date_str;
    stringstream ss (date_str);
     
    int y, m, d;

    if (ss)
    {   
        /* If year is negative is OK */  
        ss >> y;

        /* Ignore just one '-' */
        if (ss.peek() == '-')
        {
            ss.ignore(1);
        }
        else 
        {
            stringstream err;
            err << "Wrong date format: " << date_str;
            throw invalid_argument(err.str());
        }

        /* Ignore  '-' or '+' */
        bool is_neg = false;
        if (ss.peek() == '-')
        {
            is_neg = true;
            ss.ignore(1);
        }
        else if (ss.peek() == '+')
        {
            ss.ignore(1);
        }

        /* Determine if not number then error */
        if (!isdigit(ss.peek()))
        {
            stringstream err;
            err << "Wrong date format: " << date_str;
            throw invalid_argument(err.str());
        }
        
        /* Store number */
        ss >> m;
        if (is_neg)
        {
            m *= -1;
        }

        /* Ignore just one '-' */
        if (ss.peek() == '-')
        {
            ss.ignore(1);
        }
        else 
        {
            stringstream err;
            err << "Wrong date format: " << date_str;
            throw invalid_argument(err.str());
        }
      
        /* Ignore  '-' or '+' */
        is_neg = false;
        if (ss.peek() == '-')
        {
            is_neg = true;
            ss.ignore(1);
        }
        else if (ss.peek() == '+')
        {
            ss.ignore(1);
        }

        /* Determine if not number then error */
        if (!isdigit(ss.peek()))
        {
            stringstream err;
            err << "Wrong date format: " << date_str;
            throw invalid_argument(err.str());
        }
        
        /* Store number */
        ss >> d;
        if (is_neg)
        {
            d *= -1;
        }

        string err;
        if (ss >> err)
        {
            stringstream err;
            err << "Wrong date format: " << date_str;
            throw invalid_argument(err.str());
        }
    }
    
    date = Date(y, m, d);
    return s;

}

class Database
{
    public:
        void AddEvent(const Date& date, const string& event)
        {
            date_events[date].insert(event);
        }

        void DeleteEvent(const Date& date, const string& event)
        {
            if (date_events[date].count(event) != 0)
            {
                date_events[date].erase(event);
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Event not found" << endl;
            }            
        }

        void  DeleteDate(const Date& date)
        {
            int n = date_events[date].size();
            date_events.erase(date);
            cout << "Deleted " << n << " events" << endl;
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
                    cout << setw(4) << setfill('0') << event.first.GetYear() << '-' <<
                            setw(2) << setfill('0') << event.first.GetMonth() << '-' <<
                            setw(2) << setfill('0') << event.first.GetDay() <<
                            " " << str << endl;
                }
            }
        }
    private:
        map<Date, set<string>> date_events;
};

int main() {
    Database db;
    string command;
    // stringstream test("Add 0-1-2 event1\nAdd 1-2-3 event2\nFind 0-1-2\nDel 0-1-2\nPrint\nDel 1-2-3 event2\nDel 1-2-3 event2\n");
    // stringstream test("Add 0-13-32 event1\n");

    while (getline(cin, command)) 
    {
        try
        {
            stringstream ss(command);
            string todo;
            ss >> todo;
            if (todo == "Add")
            {
                Date d;
                ss >>  d;
                string event;
                ss >> event;
                db.AddEvent(d, event);
            }
            else if (todo == "Del")
            {
                Date d;
                ss >>  d;
                string event;
                if (ss.peek() == ' ')
                {
                    ss >> event;
                    db.DeleteEvent(d, event);
                }
                else
                {
                    db.DeleteDate(d);
                }
                
            }
            else if (todo == "Find")
            {
                Date d;
                ss >>  d;
                db.Find(d);
            }
            else if (todo == "Print")
            {
                db.Print();
            }
            else if (todo.size() != 0)
            {
                throw invalid_argument("Unknown command: " + todo);
            }
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            return 1;
        }
    }

    return 0;
}

// Add 1-1-1f d1
// Print
// ...
// 0001-01-01 d1