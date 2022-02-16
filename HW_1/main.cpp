#include <iostream>
#include "cmath"

#define PI 3.14159265

using namespace std;



class Phasor
{
    private:
        /* data */
        double magnitude;
        double phase;
    public:
////////////////////default constructor//////////////////////////

        Phasor(){
            this->magnitude = 0;
            this->phase = 0;

            // cout << "magnitude is " << magnitude << endl;
            // cout << "phase is " << phase << endl;
        };

/****************************************************************
 *          Programmer defined constructor
 *  Name:   Phasor()
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

        Phasor(const double x, const double y){
            this->magnitude = sqrt(pow(x,2)+pow(y,2));
            cout << "magnitude is " << magnitude << endl;
            double tempPhase = (atan(y/x) * 180 / PI);
            while (tempPhase < 0){
                tempPhase += 360;
            }
            if(tempPhase == -0){
                tempPhase = 180;
            }
            this->phase = tempPhase;
            cout << "phase is " << phase << endl;
        };

/****************************************************************
 *          Set Magnitude Function
 *  Name:   setMagnitude(double)
 *  Args:   double x
 *  Rtrn:   void
 *  Func:   Sets the magnitude of the Phasor
 *  Logic:  Check if value is negative. If it's negative, then 
 *              flip the sign and assign it to magnitude
 ****************************************************************/
         void setMagnitude(const double x){
             double temp = x;
             if(temp < 0){
                 temp = -temp;
             }
             cout << "Magnitude was " << magnitude << endl;
             this->magnitude = temp;
             cout << "Now magnitude is " << magnitude << endl;
         };


/****************************************************************
 *          Get Magnitude Function
 *  Name:   getMagnitude()
 *  Args:   None
 *  Rtrn:   Double
 *  Func:   Gets the magnitude of the Phasor
 *  Logic:  Retrieve magnitude
 ****************************************************************/

         double getMagnitude(){
             double temp = magnitude;
             return temp;
         };

/****************************************************************
 *          Set Phase Function
 *  Name:   setPhase(double)
 *  Args:   double x
 *  Rtrn:   void
 *  Func:   Sets the phase of the Phasor
 *  Logic:  Check if value is negative. If it's negative, then 
 *              add 360 until its positive. Set new phase
 ****************************************************************/
         void setPhase(double x){
            double tempX = x;
            while(tempX < 0){
                tempX += 360;
            };
            this->phase = tempX;
            cout << "Now the phase is " << phase << endl;
            
         };
        // double getPhase();


////////////////////////destructor///////////////////////////////

        //~Phasor();

};

// Phasor::Phasor(/* args */)
// {
// }

// Phasor::~Phasor()
// {
// }

int main(){
    Phasor a(-1,0);
    a.setMagnitude(4);
    double m = a.getMagnitude();
    cout << "m equals " << m << endl;
    a.setPhase(-45);
}
