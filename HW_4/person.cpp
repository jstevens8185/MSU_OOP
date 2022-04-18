
#include "person.h"
//#include "accountNum.h"
#include<iostream>
#include<string>

using namespace std;

int Person::IDGenerator = 1;

Person::Person() {
	personalID = -1;
	firstName = " ";
	lastName = " ";
	DOB = " ";
	homeCountry = NULL;
	address = " ";
    accountNumber = -1;
};

Person::Person(string fName, string lName, string dob, string saddress, string* country) {
	personalID = IDGenerator;
	firstName = fName;
	lastName = lName;
	DOB = dob;
	homeCountry = country;
	address = saddress;
	IDGenerator++;
    accountNumber = -1;
};

string Person::getFName() {
	return firstName;
}

string Person::getLName() {
	return lastName;
}

int Person::getID() {
	return personalID;
}

string Person::getDOB() {
	return DOB;
}

void Person::setAcctNum(int acctNum) {
    accountNumber = acctNum;
}


Student::Student() {
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
    switch (year)
    {
    case 1:   class_ = FRESHMAN;
        break;
    case 2:   class_ = SOPHOMORE;
        break;
    case 3:   class_ = JUNIOR;
        break;
    case 4: class_ = SENIOR;
        break;
    default:
        break;
    }
    major = maj;
    advisor = adv;
    accountNumber = -1;
}

ostream& operator<<(ostream& os, const Student& p) {
    os << "ID: " << p.personalID << endl;
    os << "Account #" << p.accountNumber;
    os << p.firstName << endl;
    os << p.lastName << endl;
    os << "Date of Birth: " << p.DOB << endl;
    switch (p.class_)
    {
    case 1: os << "Freshman" << endl;
        break;
    case 2: os << "Sophomore" << endl;
        break;
    case 3: os << "Junior" << endl;
        break;
    case 4: os << "Senior" << endl;
        break;
    default:
        break;
    }
    os << "Major: " << p.major << endl;
    os << "Advisor: " << p.advisor << endl;
    os << p.address << endl;
    os << "Originating country: " << * p.homeCountry;

    return os;
};

ostream& operator<<(ostream& os, const Person& p) {
    os << "ID: " << p.personalID << endl;
    os << "Account #" << p.accountNumber;
    os << p.firstName << endl;
    os << p.lastName << endl;
    os << p.DOB << endl;
    os << p.address << endl;
    os << "Oringinating country: " << * p.homeCountry;

    return os;
};

Faculty::Faculty() {
    personalID = -1;
    firstName = " ";
    lastName = " ";
    DOB = " ";
    homeCountry = NULL;
    address = " ";
    dept = NA;
    accountNumber = -1;
}

Faculty::Faculty(string fName, string lName, string dob, string fAddress,
    string* country, int dep)
    : Person(fName, lName, dob, fAddress, country)
{
    switch (dep)
    {    
    case 1:
        dept = MATH;
        break;
    case 2:
        dept = BIO;
        break;
    case 3:
        dept = COMPSCI;
        break;
    case 4:
        dept = PHYS;
        break;
    case 5:
        dept = ENG;
        break;
    default:
        dept = NA;
        break;
    }

    accountNumber = -1;

}

ostream& operator<<(ostream& os, const Faculty& p) {
    os << "ID: " << p.personalID << endl;
    os << "Account #" << p.accountNumber;
    os << p.firstName << endl;
    os << p.lastName << endl;
    os << "Date of Birth: " << p.DOB << endl;
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
    os << p.address << endl;
    os << "Originating country: " << * p.homeCountry;

    return os;
}
