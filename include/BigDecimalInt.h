#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <string>
#include<iostream>
using namespace std;
class BigDecimalInt
{
    public:
    char* Bigdec;
    int decimalnumber;
    BigDecimalInt (string decStr); // Initialize from string
    BigDecimalInt (int decInt); // Initialize from integer or decimal
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    int operator[](int index); // to return value of specific index
    friend ostream& operator << (ostream& os, const BigDecimalInt& n1);
    friend istream& operator>>(istream& is, BigDecimalInt& n1);
    BigDecimalInt turnNegativeIntoComplement(BigDecimalInt anotherDec);
    BigDecimalInt removeminus (BigDecimalInt anotherDec);
    BigDecimalInt addminus (BigDecimalInt anotherDec);
};

#endif // BIGDECIMALINT_H
