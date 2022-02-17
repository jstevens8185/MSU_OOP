#include "Phasor.h"
#include <cmath>
#define PI 3.14159265

////////////////////default constructor//////////////////////////

        Phasor::Phasor(){
            magnitude = 0;
            phase = 0;

            // cout << "magnitude is " << magnitude << endl;
            // cout << "phase is " << phase << endl;
        };

/****************************************************************
 *          Programmer defined constructor
 *  Name:   Phasor::Phasor()
 *  Args:   double x, double y
 *  Func:   Creates a Phasor class when passed two doubles
 *  Logic:  magnitude is the square root of (x^2 + y^2). Negatives dont
 *              matter here because the square of any number is positive
 *          To get phase we have to get the arctan of (y/x). This returns
 *              in radians. To convert to degrees we multiply by (180/PI)
 *          If the phase is negative, we add 360 degrees until the phase 
 *              is positive.
 *          If the coordinates are x = -1 and y = 0, this results in a 
 *              phase of -0. To correct this, it is hard coded to set
 *              phase to 180 degrees whenever this happens.
 ****************************************************************/

        Phasor::Phasor(const double x, const double y){
            magnitude = sqrt(pow(x,2)+pow(y,2));
            //cout << "magnitude is " << magnitude << endl;
            double tempPhase = (atan(y/x) * 180 / PI);
            while (tempPhase < 0){
                tempPhase += 360;
            }
            if(tempPhase == -0){
                tempPhase = 180;
            }
            phase = tempPhase;
            //cout << "phase is " << phase << endl;
        };

/****************************************************************
 *          Set Magnitude Function
 *  Name:   Phasor::setMagnitude(double)
 *  Args:   double x
 *  Rtrn:   void
 *  Func:   Sets the magnitude of the Phasor
 *  Logic:  Check if value is negative. If it's negative, then 
 *              flip the sign and assign it to magnitude
 ****************************************************************/
         void Phasor::setMagnitude(const double x){
             double temp = x;
             if(temp < 0){
                 temp = -temp;
             }
             //cout << "Magnitude was " << magnitude << endl;
             magnitude = temp;
             //cout << "Now magnitude is " << magnitude << endl;
         };


/****************************************************************
 *          Get Magnitude Function
 *  Name:   Phasor::getMagnitude()
 *  Args:   None
 *  Rtrn:   Double
 *  Func:   Gets the magnitude of the Phasor
 *  Logic:  Retrieve magnitude
 ****************************************************************/

         double Phasor::getMagnitude(){
             double temp = magnitude;
             return temp;
         };

/****************************************************************
 *          Set Phase Function
 *  Name:   Phasor::setPhase(double)
 *  Args:   double x
 *  Rtrn:   void
 *  Func:   Sets the phase of the Phasor
 *  Logic:  Check if value is negative. If it's negative, then 
 *              add 360 until its positive. Set new phase
 ****************************************************************/
         void Phasor::setPhase(double x){
            double tempX = x;
            while(tempX < 0){
                tempX += 360;
            };
            this->phase = tempX;
            //cout << "Now the phase is " << phase << endl;
            
         };

/****************************************************************
 *          Get Phase Function
 *  Name:   Phasor::GetPhase()
 *  Args:   None
 *  Rtrn:   Double
 *  Func:   Gets the phase of the Phasor and returns as a double
 *  Logic:  Retrieve value of the phase
 ****************************************************************/
         double Phasor::getPhase(){
             double temp = phase;
             return temp;
         };

/****************************************************************
 *          Multiply Phasors Function
 *  Name:   Phasor::operator*
 *  Args:   &Phasor
 *  Rtrn:   Phasor
 *  Func:   Multiply 2 phasors together and return the result
 *  Logic:  Pass in phasor by reference (Const Phasor &right). Create new phasor 'temp'. 
 *              Multiply 'this' phasors magnitude by &right phasors magnitude. Save result
 *              in temp.setMagnitude. Add both phasors angle. Make sure angle is positive.
 *              while angle is 360 or bigger, subtract 360. Save new angle in temp.setPhase. Return temp. 
 ****************************************************************/
         Phasor Phasor::operator*(const Phasor &right){
            Phasor temp;
            double newMag, newPhase;
            newMag = this->getMagnitude() * right.magnitude;
            newPhase = (this->getPhase() + right.phase);
            while(newPhase >= 360){
                newPhase -= 360;
            };
            while(newPhase < 0){
                newPhase += 360; 
            }
            temp.setMagnitude(newMag);
            temp.setPhase(newPhase);
            return temp;
         };

/****************************************************************
 *          Divide Phasors Function
 *  Name:   Phasor::operator/
 *  Args:   &Phasor
 *  Rtrn:   Phasor
 *  Func:   Divide 2 phasors and return the result
 *  Logic:  Pass in phasor by reference (Const Phasor &right). Create new phasor 'temp'. 
 *              Divide 'this' phasors magnitude by &right phasors magnitude. Save result
 *              in temp.setMagnitude. Subtract both phasors angle. Make sure angle is positive.
 *              while angle is 360 or bigger, subtract 360. Save new angle in temp.setPhase. Return temp. 
 ****************************************************************/
         Phasor Phasor::operator/(const Phasor &right){
            Phasor temp;
            double newMag, newPhase;
            newMag = this->getMagnitude() / right.magnitude;
            newPhase = (this->getPhase() - right.phase);
            while(newPhase >= 360){
                newPhase -= 360;
            };
            while(newPhase < 0){
                newPhase += 360; 
            }
            temp.setMagnitude(newMag);
            temp.setPhase(newPhase);
            return temp;
         };

////////////////////////destructor///////////////////////////////

        Phasor::~Phasor(){};



