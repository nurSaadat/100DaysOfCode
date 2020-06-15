#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Duration
{
    int hour;
    int min;
    Duration(int h = 0, int m = 0)
    {
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

istream& operator>>(istream& stream, Duration& duration)
{
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}


ostream& operator<<(ostream& stream, const Duration duration)
{
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':'
           << setw(2) << duration.min;   
    return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs)
{
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

void PrintVector(const vector<Duration>& durs)
{
    for (const Duration& dur : durs)
    {
        cout << dur << ' ';
    }
    cout << endl;
}

bool operator<(const Duration& lhs, const Duration& rhs)
{
    if (lhs.hour == rhs.hour)
    {
        return lhs.hour < rhs.hour;
    }
    return lhs.hour < rhs.hour;
}

int
main()
{
    /* Stream input from string */
    stringstream dur_ss("01:50");
    Duration dur1;
    dur_ss >> dur1;

    /* How stream works */
    // operator<<(operator<<(cout, "hello"), " world");

    /* operator<< should return stream */
    /* So we can output endl */
    // cout << duration1 << endl;

    /* Addition */
    Duration dur2 = {0, 35};
    cout << dur1 + dur2 << endl;

    Duration dur3 = dur1 + dur2;
    vector<Duration> v
    {
        dur3, dur2, dur1
    };
    PrintVector(v);
    sort(begin(v), end(v));
    PrintVector(v);

    return 0;
}