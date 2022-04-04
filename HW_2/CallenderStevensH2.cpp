/**************************************************
 *              H2
 * Names: Chad Callendar, Jered Stevens
 * Class: OOP 2143 - MWF 12PM
 * Date: 04/03/2022
 * 
 *************************************************/

/*************************************************
 * Program creates a fraction in the format
 *         (numerator)/(denominator)
 *************************************************/

#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    long int a = 4, b =14;
    Fraction c;
    Fraction d = 5;

    c.set(a, b);

    cout << double(c);
}