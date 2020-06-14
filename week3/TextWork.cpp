#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int
main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (input)
    {
        string str;
        while(getline(input, str))
        {
            output << str << endl;
        }
    }
    return 0;
}