#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void PrintRow(ifstream& input, int m, int width)
{
    int num;
    for (int i = 0; i < m; i++)
    {
        input >> num;
        input.ignore(1);
        cout << setw(width) << num;
        if (i < m - 1)
        {
            cout << " ";
        }
    }
}

void PrintTable(ifstream& input, int n, int m, int width)
{
    for (int i = 0; i < n; i++)
    {
        PrintRow(input, m, width);
        cout << endl;
    }
}

int 
main()
{
    ifstream input("input.txt");
    int n, m;
    input >> n >> m;
    PrintTable(input, n, m, 10);
    return 0;
}
