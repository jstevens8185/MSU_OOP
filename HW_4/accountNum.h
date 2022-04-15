#pragma once
#include "faculty.h"
#include "student.h"

struct AccountNumber{
    static int acctCounter;
    int acctNum;
    Person* owner;

    AccountNumber(){
        acctCounter = 0;
        acctNum = -1;
        owner = NULL;
    }
    AccountNumber(Faculty& fac){
        acctCounter++;
        acctNum = acctCounter;
        owner = &fac;
    }
    AccountNumber(Student& stu){
        acctCounter++;
        acctNum = (acctCounter + 1000);
        owner = &stu;
    }
};