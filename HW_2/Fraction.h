#pragma once
#include <iostream>

class Fraction
{
    private:
        long int numerator;
        long int denominator;

    public:
        Fraction() {numerator = 0, denominator = 1;}
        Fraction(const long&);
        Fraction(const long&, const long&);

        // convert a Fraction object to double
        operator double();

        Fraction exp(int);

        Fraction operator=(const Fraction&);
        
        // overloading mathematical operators
        Fraction operator*(const Fraction&);
        Fraction operator/(const Fraction&);
        Fraction operator+(const Fraction&);
        Fraction operator-(const Fraction&);
        Fraction operator-();

        //overloading comparison operators
        bool operator==(const Fraction&);
        bool operator!=(const Fraction&);
        bool operator<(const Fraction&);
        bool operator<=(const Fraction&);
        bool operator>(const Fraction&);
        bool operator>=(const Fraction&);

        Fraction set(const long&, const long&);
        
        Fraction reduce(const long&, const long&); 
        // call this function to reduce the fractions
        // first parameter is numerator and second is denominator

        //Overloading ostream
        friend std::ostream& operator<<(std::ostream&, const Fraction&);
        friend std::istream& operator>>(std::istream&, Fraction&);

        //////////////////////////////////////////
        //  Name: error()
        //  Returns: void
        //  Function: Prints error when illegal ops
        //              are attempted
        //  Params: int for switch statement
        ///////////////////////////////////////////
        void error(int);
        Fraction reciporical();
};

unsigned long GCD(unsigned long int a, unsigned long int b);
void run(Fraction,Fraction);

#include "Fraction.cpp"