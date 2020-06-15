#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int
main()
{
    return 0;
}

void TextWork2()
{
    ifstream input("input.txt");

    double i;
        
    cout << fixed << setprecision(3);

    while(input >> i)
    {
        cout << i << endl;
    }
}

void TextWork1()
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
}