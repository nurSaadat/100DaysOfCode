#include <iostream>
#include <string>
using namespace std;

struct Specialization
{
    string value;
    explicit Specialization(const string& new_val)
    {
        value = new_val;
    }
};

struct Course
{
    string value;
    explicit Course(const string& new_val)
    {
        value = new_val;
    }
};

struct Week
{
    string value;
    explicit Week(const string& new_val)
    {
        value = new_val;
    }
};

struct LectureTitle 
{
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization new_specialization, Course new_course, Week new_week)
    {
        specialization = new_specialization.value;
        course = new_course.value;
        week = new_week.value;
    }

};



