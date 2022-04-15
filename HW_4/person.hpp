
#include "person.h"
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
};

Person::Person(string fName, string lName, string dob, string saddress, string* country) {
	personalID = IDGenerator;
	firstName = fName;
	lastName = lName;
	DOB = dob;
	homeCountry = country;
	address = saddress;
	IDGenerator++;
};

string Person::getFName(){
	return firstName;
}

string Person::getLName(){
	return lastName;
}

int Person::getID(){
	return personalID;
}

string Person::getDOB(){
	return DOB;
}

ostream& operator<<(ostream& os, const Person& p) {
	os << p.personalID << endl;
	os << p.firstName << endl;
	os << p.lastName << endl;
	os << p.DOB << endl;
	os << p.address << endl;
	os << *p.homeCountry << endl;

	return os;
};