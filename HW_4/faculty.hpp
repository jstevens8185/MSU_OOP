#pragma once
#include "faculty.h"
#include <string>
#include <iostream>
using namespace std;

    Faculty::Faculty(){
        personalID = -1;
	    firstName = " ";
	    lastName = " ";
	    DOB = " ";
	    homeCountry = NULL;
	    address = " ";;
    }

    Faculty::Faculty(string fName, string lName, string dob, string saddress,
    string* country, int dep) 
    : Person(fName, lName, dob, saddress, country)
    {

    }

    ostream& operator<<(ostream& os, const Faculty& p){
        os << p.personalID << endl;
        os << p.firstName << endl;
        os << p.lastName << endl;
        switch (p.dept)
        {
        case 0:
            os << "Math Department" << endl;
            break;
        case 1:
            os << "Biology Department" << endl;
            break;
        case 2:
            os << "Computer Science Department" << endl;
            break;
        case 3:
            os << "Physics Department" << endl;
            break;
        case 4:
            os << "Engineering Department" << endl;
            break;
        case 5:
            os << "Art Department" << endl;
            break;
        case 6:
            os << "Business Department" << endl;
            break;
        default:
            break;
        }
        os << "Date of Birth: " << p.DOB << endl;
        os << p.address << endl;
        os << *p.homeCountry << endl;

        return os;
    }
