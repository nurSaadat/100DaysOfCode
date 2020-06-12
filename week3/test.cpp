#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string FindMostRecentName(int year, const map<int, string>& list)
{
  string name = "";
  for (const auto& n : list)
  {
    if (n.first <= year)
    {
      if (n.second.size() != 0)
      {
        name = n.second;
      }
    }
  }
  return name;
}

string FormNameHistory(int year, const map<int, string>& list)
{
  string prev;
  vector<string> history;
  for (const auto& n : list)
  {
    if (n.first <= year)
    {
      if (n.second != prev)
      {
        history.push_back(n.second);
      }    
    }
    prev = n.second;
  }

  string result = "";
  if (history.size() > 1)
  {
    result = history[0];
    for (int i = 1; i < history.size() - 1; i ++)
    {
      result = history[i] + ", " + result;
    }

    result = "(" + result + ")";

  }
  return result;
}

class Person 
{
public:
  Person(const string& f_name, const string& l_name, const int& year)
  {
    firstNames[year] = f_name;
    lastNames[year] = l_name;
    year_of_birth = year;
  }
  void ChangeFirstName(int year, const string& first_name) 
  {
    if (year >= year_of_birth)
    {
      firstNames[year] = first_name;
    }    
  }

  void ChangeLastName(int year, const string& last_name) 
  {
    if (year >= year_of_birth)
    {
      lastNames[year] = last_name;
    }
  }

  string GetFullName(int year) const
  {
    if (year < year_of_birth)
    {
      return "No person";
    }
    string first_name = FindMostRecentName(year, firstNames);
    string last_name = FindMostRecentName(year, lastNames);

    if (first_name.size() == 0 && last_name.size() == 0)
    {
      return "Incognito";
    }
    else if (first_name.size() == 0)
    {
      return last_name + " with unknown first name";
    }
    else if (last_name.size() == 0)
    {
      return first_name + " with unknown last name";
    }
    else
    {
        return first_name + " " + last_name;
    }
  }

  string GetFullNameWithHistory(int year) const
  {
    if (year < year_of_birth)
    {
      return "No person";
    }
    string current_first_name = FindMostRecentName(year, firstNames);
    string current_last_name = FindMostRecentName(year, lastNames);
    
    if (current_first_name.size() == 0 && current_last_name.size() == 0)
    {
      return "Incognito";
    }
    else 
    {
      string first_name_history = FormNameHistory(year, firstNames);
      string last_name_history = FormNameHistory(year, lastNames);

      if (current_last_name.size() == 0)
      {
        if (first_name_history.size() == 0)
        {
          return current_first_name + " with unknown last name";
        }
        else 
        {
          return current_first_name + " " + first_name_history + " with unknown last name";
        }               
      }
      else if (current_first_name.size() == 0)
      {
        if (last_name_history.size() == 0)
        {
          return current_last_name + " with unknown first name";
        }
        else 
        {
        return current_last_name + " " + last_name_history + " with unknown first name";     
        }
      }
      else
      {
        if (last_name_history.size() == 0 && first_name_history.size() == 0)
        {
          return current_first_name + " " + current_last_name;
        }        
        if (last_name_history.size() == 0)
        {
          return current_first_name + " " + first_name_history + " " + current_last_name;
        }
        if (first_name_history.size() == 0)
        {
          return current_first_name + " " + current_last_name + " " + last_name_history;
        }
        return current_first_name + " " + first_name_history + " " + current_last_name + " " + last_name_history;
      }
    }

  }

private: 
    map<int, string> firstNames;
    map<int, string> lastNames;
    int year_of_birth;
    };



