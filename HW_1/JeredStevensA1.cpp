//**************************************************************
//                    Assignment #1
//                    Name: Jered Stevens
//                    OOP Date: Date of Submission (02/17/2022)
//***************************************************************
//      This program creates Phasors from coordinates on a 2D plane
//      It can perform multiplication and division on the phasors.
//      This program does not take any input, therefore it is very
//      simple to operate: simply run the program.
//
//      A description and explanation of the functions in the 'Phasor'
//      class can be found above each implementation block of code.
//*****************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265
#include "Phasor.h"


using namespace std;

int main(){
    //Initialized with default constructor
    Phasor A, D;

    //Initialized with programmer defined construcor
    Phasor B(sqrt(2), -sqrt(2));
    Phasor C(sqrt(2), sqrt(3));

    //Magnitude and phase changed using member functions
    A.setMagnitude(3);
    A.setPhase(-45);

    //The overloaded operators will take care of this cases
    D = B * C;
    A = B / C;

    cout << fixed << showpoint << setprecision(2);
    cout << "=================================" << endl;
    cout << "This is A" << endl;
    cout << "Magnitude: " << A.getMagnitude() << "  Phase: " <<     A.getPhase() << endl;
    cout << "=================================" << endl;
    cout << "This is B" << endl;
    cout << "Magnitude: " << B.getMagnitude() << "  Phase: " <<     B.getPhase() << endl;
    cout << "=================================" << endl;
    cout << "This is C" << endl;
    cout << "Magnitude: " << C.getMagnitude() << "  Phase: " <<     C.getPhase() << endl;
    cout << "=================================" << endl;
    cout << "This is D" << endl;
    cout << "Magnitude: " << D.getMagnitude() << "  Phase: " <<     D.getPhase() << endl;
}

