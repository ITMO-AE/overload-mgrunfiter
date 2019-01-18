#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
public:
  Rational();
  Rational(int numerator, int denominator);

  // оператор +
  Rational operator + (Rational const &r);
  // оператор -
  Rational operator - (Rational const &r);
  // оператор *
  Rational operator * (Rational const &r);
  // оператор /
  Rational operator / (Rational const &r);
  // оператор сравнения
  friend bool operator == (const Rational &r1, const Rational &r2);
  // оператор вывода
  friend std::ostream& operator << (std::ostream &os, Rational const &r);
  // оператор ввода
  friend std::istream& operator >> (std::istream &in, Rational &r);

  int Numerator() const;
  int Denominator() const;
private:
  int numerator;
  int denominator;
protected:
  int Nod(int a, int b) const;
};

#endif // RATIONAL_H
