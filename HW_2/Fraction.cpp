#include "Fraction.h"
#include <iostream>
#include <cmath>

using namespace std;

Fraction::Fraction(const long &right)
{
    numerator = right;
    denominator = 1;
}

Fraction::Fraction(const long& num, const long& den){
    //reduce the fraction before storing
    long gcd;
    int a2, b2;

    gcd = GCD(num,den);
    //std::cout << "gcd is: " << gcd << std::endl;
    a2 = num/gcd;
    b2 = den/gcd;

    numerator = a2;
    denominator = b2;
};

Fraction Fraction::exp(int e){
    long int tempNum = pow(this->numerator,e);
    long int tempDem = pow(this->denominator,e);
    Fraction newFrac(tempNum,tempDem);
    return newFrac;
};

Fraction::operator double()
{
    return double(numerator)/denominator;
}

Fraction Fraction::operator=(const Fraction& rhs){
    this->numerator = rhs.numerator;
    this->denominator = rhs.denominator;
    return *this;
};

/**************************************************
 *          Overloaded math operators
 * funtion: perform math operations on Fractions
 *              by using the appropriate symbols
 *              ie: instead of 
 *          fraction1.multiply(fraction2);
 *              We would use:
 *          fraction1 * fraction2;
 **************************************************/
Fraction Fraction::operator*(const Fraction &right)
{
    Fraction newFrac;
    newFrac.numerator = numerator * right.numerator;
    newFrac.denominator = denominator * right.denominator;
    
    int a2, b2;
    int gcd = GCD(newFrac.numerator,newFrac.denominator);
    //std::cout << "gcd is: " << gcd << std::endl;
    a2 = newFrac.numerator/gcd;
    b2 = newFrac.denominator/gcd;

    newFrac.numerator = a2;
    newFrac.denominator = b2;

    return newFrac;
}

Fraction Fraction::operator/(const Fraction &right)
{
    Fraction newFrac;
    if(right.numerator == 0){
        std::cout << "DIVISION BY ZERO" << std::endl;
        return 0;
    }
    newFrac.numerator = numerator * right.denominator;
    newFrac.denominator = denominator * right.numerator;

    int a2, b2;
    int gcd = GCD(newFrac.numerator,newFrac.denominator);
    //std::cout << "gcd is: " << gcd << std::endl;
    a2 = newFrac.numerator/gcd;
    b2 = newFrac.denominator/gcd;

    newFrac.numerator = a2;
    newFrac.denominator = b2;

    return newFrac;
}

Fraction Fraction::operator+(const Fraction &right)
{
    Fraction newFrac;
    newFrac.numerator = (numerator * right.denominator) + (denominator * right.numerator);
    newFrac.denominator = denominator * right.denominator;

    int a2, b2;
    int gcd = GCD(newFrac.numerator,newFrac.denominator);
    //std::cout << "gcd is: " << gcd << std::endl;
    a2 = newFrac.numerator/gcd;
    b2 = newFrac.denominator/gcd;

    newFrac.numerator = a2;
    newFrac.denominator = b2;

    return newFrac;
}

Fraction Fraction::operator-(const Fraction &right)
{
    Fraction newFrac;
    newFrac.numerator = (numerator * right.denominator) - (denominator * right.numerator);
    newFrac.denominator = denominator * right.denominator;

    int a2, b2;
    int gcd = GCD(newFrac.numerator,newFrac.denominator);
    //std::cout << "gcd is: " << gcd << std::endl;
    a2 = newFrac.numerator/gcd;
    b2 = newFrac.denominator/gcd;

    newFrac.numerator = a2;
    newFrac.denominator = b2;

    return newFrac;
}


/****************************************************
 *          Comparision operators
 *  Function: used to make comparisions of 
 *              Fration objects
 ***************************************************/
bool Fraction::operator==(const Fraction &right){
    if(this->numerator==right.numerator && this->denominator==right.denominator){
        return true;
    }
    else{
        return false;
    }
}

bool Fraction::operator!=(const Fraction &right){
    if(this->numerator!=right.numerator || this->denominator!=right.denominator){
        return true;
    }
    else{
        return false;
    }
}

bool Fraction::operator<(const Fraction &right){
    int lhsNumerator = this->numerator * right.denominator;
    int rhsNumerator = this->denominator * right.numerator;
    if(lhsNumerator < rhsNumerator){
        return true;
    }else{
        return false;
    }
}

bool Fraction::operator<=(const Fraction &right){
    int lhsNumerator = this->numerator * right.denominator;
    int rhsNumerator = this->denominator * right.numerator;
    if(lhsNumerator < rhsNumerator || lhsNumerator == rhsNumerator){
        return true;
    }else{
        return false;
    }
}

bool Fraction::operator>(const Fraction &right){
    int lhsNumerator = this->numerator * right.denominator;
    int rhsNumerator = this->denominator * right.numerator;
    if(lhsNumerator > rhsNumerator){
        return true;
    }else{
        return false;
    }
}

bool Fraction::operator>=(const Fraction &right){
    int lhsNumerator = this->numerator * right.denominator;
    int rhsNumerator = this->denominator * right.numerator;
    if(lhsNumerator > rhsNumerator || lhsNumerator == rhsNumerator){
        return true;
    }else{
        return false;
    }
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
    Fraction newFrac;
    newFrac.numerator = this->numerator *-1;
    newFrac.denominator = this->denominator;
    return newFrac;;
}

Fraction Fraction::set(const long &top, const long &bottom)
{
    //reduce the fraction before storing
    long gcd;
    int a2, b2;

    gcd = GCD(top,bottom);
    //std::cout << "gcd is: " << gcd << std::endl;
    a2 = top/gcd;
    b2 = bottom/gcd;

    numerator = a2;
    denominator = b2;
        
    if(bottom==0){
        error(2);
        denominator = 1;
    }

    //std::cout << "Fraction stored as: " << numerator << "/" << denominator << std::endl;

    return *this;
}


void Fraction::error(int a){
    switch (a)
    {
        case 1:
            std::cout << "Error code 1: Illegal rational number" << std::endl;
            break;
        case 2:
            std::cout << "***Error code 2: Division by zero.***" << std::endl;
            std::cout << "Denominator will be set to 1." << std::endl;
            break;    
        default:
            break;
    }
}

Fraction Fraction::reciporical(){
    if(this->numerator == 0){
        std::cout << "DIVISION BY ZERO" << std::endl;
    }
    Fraction newFrac;
    newFrac.set(denominator,numerator);
    return newFrac;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
    if(fraction.denominator == 1){
        os << fraction.numerator;
    }else{
        os << fraction.numerator << '/' << fraction.denominator;
    }
    return os;
}


std::istream& operator>>(std::istream& in, Fraction& input) {
    int top;
    int bottom=1;
    int whole=0;
    int peekchar = 0;
    bool valid=false;

 
    //get the numerator
    in >> top; 
    //std::cout << "top is: " << top << std::endl;
    //peek at next character
    peekchar = in.peek();  

    //if next character is a /
    //skip the / character
    //get the denominator
    if(in && peekchar == '/') { 
        //std::cout << "in first if block" << std::endl;
        in.get(); 
        in >> bottom; 
        //std::cout << "bottom is: " << bottom << std::endl;
        valid = true;
    }
    //if we succeeded in reading
    if (in || valid) { 
        if (bottom == 0) {
            input.error(2);
            bottom = 1;
        }
        top += (whole*bottom);
        input = Fraction(top, bottom);
     }
     return in;
};

void run(Fraction a, Fraction b){
            cout << "PLEASE ENTER YOUR FRACTIONS AS 'A/B' WITHOUT QUOTES THEN -->ENTER." 
            << endl << endl;

        cout << "Numerator/Denominator: ";
        cin >> a;
        cout << endl << "Numerator/Denominator: ";
        cin >> b;
        cout << "-------------------------------" << endl;
        cout << "CONVERTING BOTH FRACTIONS TO DOUBLE" << endl;
        cout << a << " Converted to Double is: " << double(a) << endl;
        cout << b << " Converted to Double is: " << double(b) << endl;
        cout << "-------------------------------" << endl;
        cout << "ADDING BOTH FRACTIONS:" << endl;
        cout << a << " (+) " << b << " = " << a + b << endl;
        cout << "-------------------------------" << endl;
        cout << "SUBTRACTING BOTH FRACTIONS: " << endl;
        cout << a << " (-) " << b << " = " << a - b << endl;
        cout << "-------------------------------" << endl;
        cout << "MULTIPLYING BOTH FRACTIONS: " << endl;
        cout << a << " (*) " << b << " = " << a * b << endl;
        cout << "-------------------------------" << endl;
        cout << "DIVIDING BOTH FRACTIONS: " << endl;
        cout << a << " (/) " << b << " = " << a / b << endl;
        cout << "-------------------------------" << endl;
        cout << "NEGATING BOTH FRACTIONS: " << endl;
        cout << "The negated value for " << a << " is " << -a << endl;
        cout << "The negated value for " << b << " is " << -b << endl;
        cout << "-------------------------------" << endl;
        cout << "RECIPORICAL OF BOTH FRACTION IS:" << endl;
        cout << "The reciporical of " << a << " is " << a.reciporical() << endl;
        cout << "The reciporical of " << b << " is " << b.reciporical() << endl;
        cout << "-------------------------------" << endl;
        cout << "CHECKING IF FRACTIONS ARE EQUAL" << endl;
        if(a == b){
            cout << "Fractions are equal" << endl;
        }else{
            cout << "Fractions are NOT equal" << endl;
        }
        cout << "-------------------------------" << endl;
        cout << "CHECKING IF FRACTIONS ARE DIFFERENT" << endl;
        if(a != b){
            cout << "Fractions are different" << endl;
        }else{
            cout << "Fractions are the same" << endl;
        }
        cout << "-------------------------------" << endl;
        cout << "CHECKING IF FRACTION (A) IS LESS THAN (B)" << endl;
        if(a < b){
            cout << a << " is less than " << b << endl;
        }else{
            cout << a << " is more than " << b << endl;
        }
        cout << "-------------------------------" << endl;
        cout << "CHECKING IF FRACTION (A) IS LESS THAN OR EQUAL TO (B)" << endl;
        if(a <= b){
            cout << a << " is less than or equal to " << b << endl;
        }else{
            cout << a << " is more than " << b << endl;
        }
        cout << "-------------------------------" << endl;
        cout << "CHECKING IF FRACTION (A) IS MORE THAN (B)" << endl;
        if(a > b){
            cout << a << " is more than " << b << endl;
        }else{
            cout << a << " is less than " << b << endl;
        }
        cout << "-------------------------------" << endl;
        cout << "CHECKING IF FRACTION (A) IS MORE THAN OR EQUAL TO (B)" << endl;
        if(a >= b){
            cout << a << " is more than or equal to " << b << endl;
        }else{
            cout << a << " is less than " << b << endl;
        }
        cout << "-------------------------------" << endl;
        cout << "ASSIGNING A NEW VALUE TO A FRACTION:" << endl;
        cout << "Please type a new value for Fraction A:" << endl << endl;
        cout << "Numerator/Denominator: ";
        cin >> a;
        cout << "Please type a new value for Fraction B:" << endl << endl;
        cout << "Numerator/Denominator: ";
        cin >> b;
        cout << "New Value for A is: " << a << endl;
        cout << "New Value for B is: " << b << endl;
        cout << "FRACTIONS TO THE POWER OF i :" << endl;
        cout << "Please enter the power value i: " << endl;
        int i;
        cin >> i;
        cout << a << " to the power of " << i << " is: " << a.exp(i) << endl;
        cout << b << " to the power of " << i << " is: " << b.exp(i) << endl;

}

unsigned long GCD(unsigned long int a, unsigned long int b)
{
     if (b == 0) // if b becomes 0 return a   
        return a;  
    return GCD(b, a % b); 
}