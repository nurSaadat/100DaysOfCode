#include <iostream>
#include <vector>
using namespace std;

class Incognizable
{
    public:
    Incognizable() {}
    Incognizable(const int& i )
    {
        f1 = i;
    }
    Incognizable(const int& i1, const int& i2)
    {
        f1 = i1;
        f2 = i2;
    }

    private:
    int f1, f2;

};

/* Alternative */
// struct Incognizable {
//   int x = 0;
//   int y = 0;
// };

// int main() {
//   Incognizable a;
//   Incognizable b = {};
//   Incognizable c = {0};
//   Incognizable d = {0, 1};
//   return 0;
// }