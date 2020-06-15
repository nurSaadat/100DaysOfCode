#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Students
{
    public:
        Students(string fname, 
                 string lname, 
                 string d, 
                 string m, 
                 string y)
        {
            firstname = fname;
            lastname = lname;
            day = d;
            month = m;
            year = y;
        }

        string GetName() const
        {
            return firstname + " " + lastname;
        }

        string GetBirthDate() const
        {
            return day + "." + month + "." + year;
        }

    private:
        string firstname, 
               lastname, 
               day, 
               month, 
               year;
};

string RetrieveInfo(vector<Students>& students)
{
    string request;
    int idx;
    cin >> request >> idx;
    // To start from zero
    idx -= 1;

    if ((request == "name" || request == "date") && (idx >= 0 && idx < students.size()))
    {

        if (request == "name")
        {
            return students[idx].GetName();
        } 

        if (request == "date")
        {
            return students[idx].GetBirthDate();
        }
    }
    else
    {
        return "bad request";
    }
    
}

void ReadStudentInfo(vector<Students>& students)
{
    string fname, lname;
    string d, m, y;
    cin >> fname >> lname >> d >> m >> y;
    students.push_back({fname, lname, d, m, y});
}

int 
main()
{
    int stud_num;
    cin >> stud_num;
    vector<Students> students;

    for (int i = 0; i < stud_num; i++)
    {
        ReadStudentInfo(students);
    }

    int req_num;
    cin >> req_num;

    for (int i = 0; i < req_num; i++)
    {
        cout << RetrieveInfo(students) << endl;
    }

    return 0;
}

// 3
// Ivan Ivanov 1 1 1901
// Petr Petrox 2 2 1902
// Alexander Sidorov 3 3 1903
// 3
// name 1
// date 3
// mark 5