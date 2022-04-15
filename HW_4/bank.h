#pragma once
#include <iostream>
#include <string>
#include "person.h"
#include "student.h"
#include <vector>
#include "faculty.h"
#include "accountNum.h"
using namespace std;


class Bank{
    private:
        int TotalMoneyInBank;
        string countries[140];
        vector <Student> studentList;
        vector <Faculty> facultyList;
        vector <AccountNumber> accounts;
    protected:

    public:
    Bank();
    void RunTheBank();
    void buildCountryList();
    void createNewAccount();
    void printAllCountries();
};

#include "bank.hpp"