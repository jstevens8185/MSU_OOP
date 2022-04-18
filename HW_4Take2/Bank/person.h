#pragma once

/*********************************
*       person.h
*   What is it:
*       Contains header for:
*           class Person
*           class Faculty
*           class Student
* 
*   Author: Jered Stevens
*   Date:   4/16/22
*/

#include<string>
#include <iostream>

using namespace std;

/************************************
*       class Person
*   What is it:
*       creates a class to
*       represent a person
*       
*   Protected members:
*       int personalID
*       string firstName
*       string lastName
*       string DOB
*       string* homeCountry
*       string  address
*       int accountNumber
*       static int IDGenerator
* 
*   Functions:
*       ---Constructors---
*       Person()
*       Person(string, string, string, string, string*)
*       ------------------
*       string getFName()
*       string getLName()
*       string getDOB()
*       int getID()
*       void setAcctNum()
*       
*       ostream& operator<<(ostream& os, const Person& p)
*/


class Person {
private:

protected:
    int personalID;
    std::string firstName;
    std::string lastName;
    std::string DOB;
    std::string* homeCountry;
    std::string address;
    int accountNumber;
    static int IDGenerator;
public:
    Person();
    Person(std::string fName, std::string lName, std::string  dob, std::string  sAddress, std::string* country);
    std::string getFName();
    std::string getLName();
    std::string getDOB();
    int getID();
    void setAcctNum(int acctNum);

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

/************************************
*       class Student
*   What is it:
*       creates a class to
*       represent a student.
*       Derived from Person
*
*   Protected members:
*       (all protected members from Person)
*       classification class_
*       string major
*       string advisor
*
*   Functions:
*       ---Constructors---
*       Student()
*       Student(string, string, string, string, string*, string, string, int)
*       ------------------
        (all functions from Person)
*
*       ostream& operator<<(ostream& os, const Student& p)
*/

enum classification { FRESHMAN = 1, SOPHOMORE = 2, JUNIOR = 3, SENIOR = 4 };

class Student : public Person
{
private:

protected:
    
    classification class_;
    string major;
    string advisor;
public:
    Student();
    Student(string fName, string lName, string dob, string saddress,
        string* country, string maj, string adv, int year);

    friend std::ostream& operator<<(std::ostream& os, const Student& p);

};


/************************************
*       class Faculty
*   What is it:
*       creates a class to represent
*       a Faculty member.
*       Derived from Person
*
*   Protected members:
*       (all protected members from Person)
*       enum department
*
*   Functions:
*       ---Constructors---
*       Faculty()
*       Faculty(string, string, string, string, string*, int)
*       ------------------
        (all functions from Person)
*
*       ostream& operator<<(ostream& os, const Faculty& p)
*/

enum department { MATH, BIO, COMPSCI, PHYS, ENG, NA };


class Faculty :public Person
{
private:

protected:
    department dept;
public:
    Faculty();
    Faculty(string fName, string lName, string dob, string fAddress,
        string* country, int dep);

    friend std::ostream& operator<<(std::ostream& os, const Faculty& p);

};