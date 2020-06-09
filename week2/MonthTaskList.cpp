#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Add(vector<vector<string>>& list);
void Dump(const vector<vector<string>>& list);
void Next(vector<vector<string>>& list, int& month_num);

int
main()
{
    vector<vector<string>> month_list(31, vector<string>());
    int month_num = 0;

    int oper_num;
    cin >> oper_num;
    for (int i = 0; i < oper_num; ++i)
    {
        string oper;
        cin >> oper;
        if (oper == "ADD")
            Add(month_list);
        if (oper == "NEXT")
        {
            Next(month_list, month_num);
        }
        if (oper == "DUMP")
            Dump(month_list);
    }

    return 0;
}

void Add(vector<vector<string>>& list)
{
    int date;
    string task;
    cin >> date >> task;
    list[date - 1].push_back(task);
}

void Dump(const vector<vector<string>>& list)
{
    int date;
    cin >> date;
    cout << list[date - 1].size() << " ";
    for (auto task : list[date - 1])
    {
        cout << task << " ";
    }
    cout << endl;
}

void Next(vector<vector<string>>& list, int& month_num)
{
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /* Calculate next month number */
    int next_m;
    if (month_num == 11)
        next_m = 0;
    else 
        next_m = month_num + 1; 

    /* If more days - expand */
    if (days[next_m] > days[month_num])
        list.resize(days[next_m], vector<string>());
        
    else if (days[next_m] < days[month_num])
    {
        int cur_day = days[month_num] - 1;
        while (cur_day > days[next_m] - 1)
        {
            for (auto task : list[cur_day])
                list[days[next_m] - 1].push_back(task);
            cur_day--;
        }
        list.resize(days[next_m]);
    }
    month_num = next_m;
}