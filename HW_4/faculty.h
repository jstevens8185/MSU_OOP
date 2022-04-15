#pragma once
#include "person.h"
#include <iostream>
#include <string>
using namespace std;

class Faculty:public Person 
{
    private:

    protected:
        enum department {MATH, BIO, COMPSCI, PHYS, ENG, ART, BUSI};
        department dept;
    public:
        Faculty();
        Faculty(string fName, string lName, string dob, string saddress,
        string* country, int dep);

    friend std::ostream& operator<<(std::ostream& os, const Faculty& p);

};

#include "faculty.hpp"