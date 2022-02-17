#ifndef PHASOR_H
#define PHASOR_H


class Phasor
{
    private:
        double magnitude;
        double phase;
    public:
////////////////////default constructor//////////////////////////

        Phasor();

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

        Phasor(const double, const double);

/****************************************************************
 *          Set Magnitude Function
 *  Name:   setMagnitude(double)
 *  Args:   double x
 *  Rtrn:   void
 *  Func:   Sets the magnitude of the Phasor
 *  Logic:  Check if value is negative. If it's negative, then 
 *              flip the sign and assign it to magnitude
 ****************************************************************/

         void setMagnitude(const double);


/****************************************************************
 *          Get Magnitude Function
 *  Name:   getMagnitude()
 *  Args:   None
 *  Rtrn:   Double
 *  Func:   Gets the magnitude of the Phasor
 *  Logic:  Retrieve magnitude
 ****************************************************************/

         double getMagnitude();

/****************************************************************
 *          Set Phase Function
 *  Name:   setPhase(double)
 *  Args:   double x
 *  Rtrn:   void
 *  Func:   Sets the phase of the Phasor
 *  Logic:  Check if value is negative. If it's negative, then 
 *              add 360 until its positive. Set new phase
 ****************************************************************/
         void setPhase(double);

/****************************************************************
 *          Get Phase Function
 *  Name:   GetPhase()
 *  Args:   None
 *  Rtrn:   Double
 *  Func:   Gets the phase of the Phasor and returns as a double
 *  Logic:  Retrieve value of the phase
 ****************************************************************/
         double getPhase();

/****************************************************************
 *          Multiply Phasors Function
 *  Name:   operator*
 *  Args:   &Phasor
 *  Rtrn:   Phasor
 *  Func:   Multiply 2 phasors together and return the result
 *  Logic:  Pass in phasor by reference (Const Phasor &right). Create new phasor 'temp'. 
 *              Multiply 'this' phasors magnitude by &right phasors magnitude. Save result
 *              in temp.setMagnitude. Add both phasors angle. Make sure angle is positive.
 *              while angle is 360 or bigger, subtract 360. Save new angle in temp.setPhase. Return temp. 
 ****************************************************************/
         Phasor operator*(const Phasor &);

/****************************************************************
 *          Divide Phasors Function
 *  Name:   operator/
 *  Args:   &Phasor
 *  Rtrn:   Phasor
 *  Func:   Divide 2 phasors and return the result
 *  Logic:  Pass in phasor by reference (Const Phasor &right). Create new phasor 'temp'. 
 *              Divide 'this' phasors magnitude by &right phasors magnitude. Save result
 *              in temp.setMagnitude. Subtract both phasors angle. Make sure angle is positive.
 *              while angle is 360 or bigger, subtract 360. Save new angle in temp.setPhase. Return temp. 
 ****************************************************************/
         Phasor operator/(const Phasor &);

////////////////////////destructor///////////////////////////////

        ~Phasor();

};



#endif