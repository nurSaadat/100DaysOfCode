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
            if (denominator == 0)
            {
                throw invalid_argument("Invalid argument");
            }
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

/* Equality */
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

/* Addition */
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

/* Substraction */
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

/* Multiplication */
Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

/* Division */
Rational operator/(const Rational& lhs, const Rational& rhs)
{
    if (lhs.Denominator() * rhs.Numerator() == 0)
    {
        throw domain_error("Division by zero");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

/* Input */
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

/* Output */
ostream& operator<<(ostream& s, const Rational& r)
{
    s << r.Numerator() << '/' << r.Denominator();
    return s;
}

/* Less */
bool operator<(const Rational& lhs, const Rational& rhs)
{
    if (lhs.Denominator() == rhs.Denominator())
    {
        return lhs.Numerator() < rhs.Numerator();
    }
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}


int 
main() {
    /* Reading */
    Rational r1, r2;
    char oper;

    try 
    {
        cin >> r1 >> oper >> r2;
    
        if (oper == '+')
        {
            cout << r1 + r2;
        }

        if (oper == '-')
        {
            cout << r1 - r2;
        }

        if (oper == '*')
        {
            cout << r1 * r2;
        }

        if (oper == '/')
        {
            cout << r1 / r2;
        }
    } 
    catch (invalid_argument&  ex)
    {
        cout << ex.what();
    }
    catch (domain_error& ex)
    {
        cout << ex.what();
    }
   
    cout << endl;
    return 0;
}
