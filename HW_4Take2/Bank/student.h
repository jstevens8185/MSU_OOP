#pragma once

#include <string>
#include <iostream>

using namespace std;

class Student : public Person
{
private:

protected:
    enum classification { FRESHMAN = 1, SOPHOMORE = 2, JUNIOR = 3, SENIOR = 4 };
    classification class_;
    string major;
    string advisor;
public:
    Student();
    Student(string fName, string lName, string dob, string saddress,
        string* country, string maj, string adv, int year);

    friend std::ostream& operator<<(std::ostream& os, const Student& p);

};