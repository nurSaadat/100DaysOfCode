#include <iostream>
#include <vector>
using namespace std;

vector<int> DaysMoreThanMean(const vector<int>& ts)
{
    int sum = 0, mean;
    vector<int> nums; 
    for (auto t : ts)
        sum += t;
    
    mean = sum / ts.size();

    for (int i = 0; i < ts.size(); ++i)
    {
        if (ts[i] > mean)
            nums.push_back(i);
    }       

    return nums;
}

int 
main()
{
    int n;
    vector<int> temperature;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int entry;
        cin >> entry;
        temperature.push_back(entry);
    }

    vector<int> num = DaysMoreThanMean(temperature);
    
    cout << num.size() << endl;
    for (auto n : num)
    {
        cout << n << " ";
    }
    
    return 0;
}