#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class SortedStrings 
{
public:
  void AddString(const string& s) 
  {
    sortedStrings.push_back(s);
    sort(begin(sortedStrings), end(sortedStrings));
  }
  vector<string> GetSortedStrings() 
  {
    return sortedStrings;
  }
private:
    vector<string> sortedStrings;
};

class Person 
{
public:
  void ChangeFirstName(int year, const string& first_name) 
  {
    namesChronology[year].f_name = first_name;
  }

  void ChangeLastName(int year, const string& last_name) 
  {
    namesChronology[year].l_name = last_name;
  }

  string GetFullName(int year) 
  {
    string fName = "";
    string lName = "";

    for (const auto& n : namesChronology)
    {
      if (n.first <= year)
      {
        if (n.second.f_name.size() != 0)
        {
          fName = n.second.f_name;
        }
        if (n.second.l_name.size() != 0)
        {
          lName = n.second.l_name;
        }
      }
    }

    if (fName.size() == 0 && lName.size() == 0)
    {
      return "Incognito";
    }
    else if (fName.size() == 0)
    {
      return lName + " with unknown first name";
    }
    else if (lName.size() == 0)
    {
      return fName + " with unknown last name";
    }
    else
    {
        return fName + " " + lName;
    }
  }

private:
    struct Name 
    {
        string f_name;
        string l_name;
    };
    map<int, Name> namesChronology;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}