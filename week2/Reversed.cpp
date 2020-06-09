#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
    vector<int> rev;
    for (int i = v.size() - 1; i >= 0; --i)
    {
        rev.push_back(v[i]);
    }
    return rev;
}