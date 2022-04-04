#include "Fraction.h"
#include <iostream>

Fraction::Fraction(const long &right)
{
    numerator = right;
    denominator = 1;
}

Fraction::operator double()
{
    return double(numerator)/denominator;
}

Fraction Fraction::operator*(const Fraction &right)
{
    numerator = numerator * right.numerator;
    denominator = denominator * right.denominator;

    return *this;
}

Fraction Fraction::operator/(const Fraction &right)
{
    numerator = numerator * right.denominator;
    denominator = denominator * right.numerator;

    return *this;
}

Fraction Fraction::operator+(const Fraction &right)
{
    numerator = (numerator * right.denominator) + (denominator * right.numerator);
    denominator = denominator * right.denominator;

    return *this;
}

Fraction Fraction::operator-(const Fraction &right)
{
    numerator = (numerator * right.denominator) - (denominator * right.numerator);
    denominator = denominator * right.denominator;

    return *this;
}

/**************************************************
 * Name: operator-()
 * Function: Negates the fraction
 * Params: none
 * Returns: Fraction
 * Logic: Flips sign of the numerator
 **************************************************/
Fraction Fraction::operator-()
{
    numerator *= -1;
    
    return *this;
}

Fraction Fraction::set(const long &a, const long &b)
{
    //reduce the fraction before storing
    long gcd;
    int a2, b2;

    gcd = GCD(a,b);
    //std::cout << "gcd is: " << gcd << std::endl;
    a2 = a/gcd;
    b2 = b/gcd;

    numerator = a2;
    denominator = b2;
        
    if(b==0){
        error(2);
        denominator = 1;
    }

    //std::cout << "Fraction stored as: " << numerator << "/" << denominator << std::endl;

    return *this;
}


unsigned long GCD(unsigned long int a, unsigned long int b)
{
     if (b == 0) // if b becomes 0 return a   
        return a;  
    return GCD(b, a % b); 
}

void Fraction::error(int a){
    switch (a)
    {
    case 1:
        std::cout << "Error code 1: Illegal rational number" << std::endl;
        break;
    case 2:
        std::cout << "Error code 2: Division by zero." << std::endl;
        std::cout << "Denominator will be set to 1." << std::endl;
        break;    
    default:
        break;
    }
}