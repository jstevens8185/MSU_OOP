// /*********************************************
//  *          student.cpp
//  * Author:
//  *      Jered Stevens
//  * Date:
//  *      4/13/22 
//  * What is it:
//  *      implementation file for student.h
//  *********************************************/
#pragma once
#include "student.h"
#include <string>
#include <iostream>
using namespace std;

    Student::Student(){
        personalID = -1;
	    firstName = " ";
	    lastName = " ";
	    DOB = " ";
	    homeCountry = NULL;
	    address = " ";;
    }
    Student::Student(string fName, string lName, string dob, string saddress,
    string* country, string maj, string adv, int year) 
    : Person(fName, lName, dob, saddress, country)
    {
        class_ = static_cast<classification>(year);
        major = maj;
        advisor = adv;
    }

    ostream& operator<<(ostream& os, const Student& p) {
	os << p.personalID << endl;
	os << p.firstName << endl;
	os << p.lastName << endl;
    switch (p.class_)
    {
    case 1  : os << "Freshman" << endl;
        break;
    case 2  : os << "Sophomore" << endl;
        break;
    case 3  : os << "Junior" << endl;
        break;
    case 4  : os << "Senior" << endl;
        break;
    default:
        break;
    }
    os << "Major: " << p.major << endl;
    os << "Advisor: " << p.advisor << endl;
	os << "Date of Birth: " << p.DOB << endl;
	os << p.address << endl;
	os << *p.homeCountry << endl;

	return os;
};