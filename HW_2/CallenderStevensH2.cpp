/**************************************************
 *              H2
 * Names: Jered Stevens
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
#include <string>

using namespace std;

int main()
{
    int decision = 1;
    Fraction a,b;

    while(decision != 0){
        run(a,b);
        cout << "WOULD YOU LIKE TO START OVER? YES--->(any number other than 0) ";
        cout << "NO--->(Enter 0)" << endl;
        cin >> decision;
    }
};