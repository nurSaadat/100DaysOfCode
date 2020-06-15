#include <iostream>

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


int main() 
{
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}