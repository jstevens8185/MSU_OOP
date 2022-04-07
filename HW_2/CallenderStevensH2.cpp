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
    long int a = 4, b = 14;
    Fraction c;
    Fraction d = 5;
    Fraction e(2,7);


    c.set(a, b);

    // if(c!=d){
    //     cout << "C and D are not equal" << endl;
    // }else{
    //     cout << "your not equal operator is broken" << endl;
    // };

    // if(c!=e){
    //     cout << "Your not equal operator is broken" << endl;
    // }else{
    //     cout << "c and e are equal" << endl;
    // };

    // if(e>=c){
    //     cout << "It's an older code but it checks out" << endl;
    // }else{
    //     cout << "less than operator is broken" << endl;
    // }


    cout << "c is " << c << endl;
    cout << "reciporical of c is " << c.reciporical() << endl;
    cout << "c to the power of 3 is: " << c.exp(3) << endl;
    cout << "c as a double is " << double(c) << endl;
    c = d;
    cout << "c is now equal to d. C is: " << c << endl;
}