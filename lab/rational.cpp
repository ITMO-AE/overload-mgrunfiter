#include "rational.h"
#include <iostream>
#include <cassert>

Rational::Rational() :
    numerator(0), denominator(1){}

Rational::Rational(int num, int den)
{
    int nod = 0;

    assert(den != 0);

    if (num == 0) {
        den = 1;
    }
    else {
        if (((num < 0) && (den < 0)) || ((num > 0) && (den > 0))) {
            num = abs(num);
            den = abs(den);
        }
        else {
            if ((num < 0) || (den < 0))
                num = abs(num) * -1;
            den = abs(den);
        }
    }
    nod = Nod(num, den);
    numerator = num / nod;
    denominator = den / nod;
}

// оператор +
Rational Rational::operator + (Rational const &r)
{
    if (denominator == r.Denominator()) {
        numerator = Numerator() + r.Numerator();
    }
    else {
        numerator = Numerator() * r.Denominator() + r.Numerator() * Denominator();
        denominator = Denominator() * r.Denominator();
    }
    return Rational(Numerator(), Denominator());
}

// оператор -
Rational Rational::operator - (Rational const &r)
{
    if (denominator == r.Denominator()) {
        numerator = Numerator() - r.Numerator();
    }
    else {
        numerator = Numerator() * r.Denominator() - r.Numerator() * Denominator();
        denominator = Denominator() * r.Denominator();
    }
    return Rational(Numerator(), Denominator());
}

// оператор *
Rational Rational::operator * (Rational const &r)
{
    return Rational(Numerator() * r.Numerator(), Denominator() * r.Denominator());
}

// оператор /
Rational Rational::operator / (Rational const &r)
{
    return Rational(Numerator() * r.Denominator(), Denominator() * r.Numerator());
}

// оператор сравнения
bool operator == (const Rational &r1, const Rational &r2)
{
    return ((r1.Numerator() == r2.Numerator()) && (r1.Denominator() == r2.Denominator()));
}

// оператор вывода
std::ostream& operator << (std::ostream &os, Rational const &r)
{
    return os << r.Numerator() << "/" << r.Denominator();
}
// оператор ввода
std::istream& operator >> (std::istream &in, Rational &r)
{
    int a, b;
    char delimiter = '/';
    char empty = ' ';

    if (in >> a && in >> delimiter && in >> b) {
        r = Rational(a, b);
        return in;
    }
    else {
        in >> empty;
        return in;
    }
}

int Rational::Numerator() const
{
    return numerator;
}

int Rational::Denominator() const
{
    return denominator;
}

int Rational::Nod(int a, int b) const
{
    if (b == 0)
        return a;
    else
        return Nod(b, (a % b));
}
