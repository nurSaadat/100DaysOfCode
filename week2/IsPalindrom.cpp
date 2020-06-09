#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom( string s )
{
    if (s == "")
    {
        return true;
    }
    int left, right;
    left = 0;
    right = s.size() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;

}

int
main()
{
    string s;
    cin >> s;
    cout << IsPalindrom(s);
    return 0;
}