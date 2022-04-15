/*********************************************
 *          person.h
 * Author:
 *      Jered Stevens
 * Date:
 *      4/13/22 
 * What is it:
 *      implementation file for person.h
 *********************************************/


#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        
    protected:
        int personalID;
        string firstName;
        string lastName;
        string DOB;
        string* homeCountry;
        string address;
        static int IDGenerator;
    public:
        Person();
        Person(string fName, string lName, string  dob, string  sAddress,  string* country);
        string getFName();
        string getLName();
        string getDOB();
        int getID();

        friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
  
#include "person.hpp"