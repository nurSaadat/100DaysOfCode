#include <iostream>
#include <string>
using namespace std;

class ReversibleString{
    public:
    ReversibleString() {}
    ReversibleString(const string& str)
    {
        theString = str;
    }
    void Reverse(){
        string reversed = "";
        for(int i = theString.size() - 1; i >= 0; i--)
        {
            reversed = reversed + theString[i];
        }
        theString = reversed;
    }
    string ToString() const {
        return theString;
    }
    private:
    string theString;
};
