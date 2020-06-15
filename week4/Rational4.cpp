#include <iostream>
#include <string>
#include <iomanip>

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
                int gcd = GCD(numerator, denominator);
                num = numerator / gcd;
                denom = denominator / gcd;

                if (denom < 0)
                {
                    num *= -1;
                }
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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
