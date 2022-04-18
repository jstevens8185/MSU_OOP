
/**********************************
*               bank.h
*   What is it:
*       contains header file for:
*           struct AccountNumber
*           class Bank
*   Author: Jered Stevens
*   Date:   4/16/2022
***********************************/


#pragma once

#include <string>
#include <vector>
#include "person.h"


using namespace std;


/****************************************
*       Struct AccountNumber
*   What is it:
*       Creates a structure containing
*           -static int acctCounter
*           -int acctNum
*           -Student* studentOwner
*           -Faculty* facultyOwner
*           -double moneyInAccount
*       to be used in conjunction with
*       class bank. 
* 
*   Functions:
*           ---Constructors---
*       AccountNumber()
*       AccountNumber(Faculty&)
*       AccountNumber(Faculty&, double)
*       AcountNumber(Student&)
*       AccountNumber(Student&, double)
*           ------------------
*       int getAccountNum()   
*       Student getStudent()    
*       Faculty getFaculty()
*       double getBalance()
*****************************************/

struct AccountNumber {
private:
    static int acctCounter;
    int acctNum;
    Student* studentOwner;
    Faculty* facultyOwner;
    double moneyInAccount;
public:
    AccountNumber();
    AccountNumber(Faculty& fac);
    AccountNumber(Faculty& fac, double initDep);
    AccountNumber(Student& stu);
    AccountNumber(Student& stu, double initDep);
    int getAccountNum();
    Student getStudent();
    Faculty getFaculty();
    double getBalance();
};

/**************************************
*           class Bank
*   What is it:
*       Creates a class that simulates a 
*       bank. Holds an array of countries,
*       a list of students, a list of
*       faculty, a list of student accounts,
*       and a list of faculty accounts.
*       Has the capability of adding new accounts,
*       accessing of stored accounts, depositing
*       money, withdrawing money, and sending 
*       money to other accounts.
* 
*   Private members:
*       double TotalMoneyInBank
*       string countries[140]
*       vector <Student*> studentList
*       vector <Faculty*> facultyList
*       vector <Account*> studentAccounts
*       vector <Account*> facultyAccounts
* 
*   Functions:
*       Bank()         //constructor
*       void accessExistingAccount()
*       void buildCountryList()
*       void createNewAccount()
*       string* findCountry(const string&)
*       void printAllCountries()
*       void printFacultyAccounts()
*       void printFacultyList()
*       void printStudentAccounts()
*       void printStudentList()
*       void RunTheBank()
*       
*******************************************/

class Bank {
private:
    double TotalMoneyInBank;
    string countries[140];
    vector <Student*> studentList;
    vector <Faculty*> facultyList;
    vector <AccountNumber*> studentAccounts;
    vector <AccountNumber*> facultyAccounts;
protected:

public:
    Bank();
    void RunTheBank();
    void buildCountryList();
    void createNewAccount();
    void printAllCountries();
    void accessExistingAccount();
    void printStudentAccounts();
    void printStudentList();
    void printFacultyAccounts();
    void printFacultyList();
    string* findCountry(const string& country);
};


