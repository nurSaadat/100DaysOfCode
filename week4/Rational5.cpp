#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Rational {
    public:
        Rational()
        {
            num = 0;
            denom = 1;
        }
        Rational(int numerator, int denominator)
        {
            if (numerator == 0)
            {
                num = 0;
                denom = 1;
            }
            else 
            {
                if (denominator < 0)
                {
                    denominator *= -1;
                    numerator *= -1;
                }

                bool is_negative = false;
                if (numerator < 0)
                {
                    is_negative = true;
                    numerator *= -1;
                }

                int gcd = GCD(numerator, denominator);
                num = numerator / gcd;
                if (is_negative)
                {
                    num *= -1;
                }
                denom = denominator / gcd;
            } 
        }

        int Numerator() const
        {
            return num;
        }

        int Denominator() const
        {
            return denom;
        }

    private:
        int num;
        int denom;

        int GCD(int a, int b)
        {
            while (a > 0 && b > 0)
            {
                if (a > b)
                {
                    a %= b;
                }
                else 
                {
                    b %= a;
                }
            }
            return a + b;
        }
};

bool operator==(const Rational& lhs, const Rational& rhs)
{
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
    {
        return true;
    }
    else
    {
        return false;
    }
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    if (rhs.Denominator() == lhs.Denominator())
    {
        return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
    }
    else
    {
        return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), 
                        lhs.Denominator() * rhs.Denominator());
    }
    
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    if (rhs.Denominator() == lhs.Denominator())
    {
        return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
    }
    else
    {
        return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), 
                        lhs.Denominator() * rhs.Denominator());
    }
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

istream& operator>>(istream& s, Rational& r)
{
    int num = r.Numerator();
    int denom = r.Denominator();

    if (s)
    {       
        s >> num;
        s.ignore(1);
        s >> denom;
    }

    r = Rational(num, denom);
    return s;

}

ostream& operator<<(ostream& s, const Rational& r)
{
    s << r.Numerator() << '/' << r.Denominator();
    return s;
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
    if (lhs.Denominator() == rhs.Denominator())
    {
        return lhs.Numerator() < rhs.Numerator();
    }
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}


int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
