#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Worry(vector<int>& q);
void Quiet(vector<int>& q);
void Come(vector<int>& q);
void WorryCount(const vector<int>& q);

int
main()
{
    vector<int> queue;
    int num_of_operations;
    cin >> num_of_operations;

    for (int i = 0; i < num_of_operations; ++i)
    {
        string operation;        
        cin >> operation;
        if (operation == "WORRY")
            Worry(queue);
        if (operation == "QUIET")
            Quiet(queue);
        if (operation == "COME")
            Come(queue);
        if (operation == "WORRY_COUNT")
            WorryCount(queue);        
    }

    return 0;
}

void Worry(vector<int>& q)
{
    int idx;
    cin >> idx;
    q[idx] = 1;
}

void Quiet(vector<int>& q)
{
    int idx;
    cin >> idx;
    q[idx] = 0;
}


void Come(vector<int>& q)
{
    int num;
    cin >> num;
    if (num > 0)
    {
        for (int i = 0; i < num; ++i)
        {
            q.push_back(0);
        }
    }
    else 
    {
        q.resize(q.size() + num);
    }
}

void WorryCount(const vector<int>& q)
{
    int count = 0;
    for (auto el : q)
    {
        if (el == 1)
        {
            count++;
        } 
    }
    cout << count << endl;
}
