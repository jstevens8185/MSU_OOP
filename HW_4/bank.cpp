#pragma once

/********************************************
*           bank.cpp
*   What is it:
*       contains the implementation for the 
*       file: bank.h
*       
*   Author: Jered Stevens
*   Date: 4/16/2022
*********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "person.h"
#include "bank.h"

using namespace std;


/*************************************
*   INCOMPLETE FUNCTION
*   Function Name:
*       accessExistingAccount()
*   Returns: 
*       void
*   Params: none
*   What it does:
*       Allows user to access an account
*       that already exists within the
*       system to see information, deposit,
*       withdraw, or send money to another account
***************************************/
void Bank::accessExistingAccount() {
    cout << "Are you a ";
    cout << "1) Student ";
    cout << "or 2) Faculty Member?" << endl;
    cout << "Enter 1 or 2 to choose: ";
    int choice = 0;
    cin >> choice;

    return;
}



/*****************************************
*   Function Name:
*       Bank()
*   Params:
*       none
*   What it does:
*       constructor for class bank.
*       sets TotalMoneyInBand to 0 and
*       populates array of countries.
******************************************/
Bank::Bank() {
    TotalMoneyInBank = 0;
    buildCountryList();

}



/*******************************************
*   Function Name:
*       buildCountryList()
*   Params:
*       none
*   Returns:
*       void
*   What it does:
*       builds an array of strings from 
*       file: "countryList.txt"
*       to use for reference when a user
*       enters their country when creating
*       an account.
********************************************/
void Bank::buildCountryList() {
    //cout << "in buildCountryList()" << endl;
    fstream in;
    in.open("countryList.txt");
    int count = 0;
    string line;
    cin.sync();
    while (std::getline(in, line))
    {
    //cout << line << endl;
        for (int i = 0; i < line.length(); i++) {
            char a = tolower(line[i]);
            line[i] = a;
        }
        //cout << "saving " << line << endl;
        countries[count] = line;
        count++;
    }
    in.close();

    return;
}


/**************************************************
*   Function Name:
*       createNewAccount()
*   Params:
*       none
*   Returns:
*       void
*   What it does:
*       Gets input from user to create a new account.
*       Creates either a new Student or new Faculty.
*       Links a new accountNumber to the new Person.
*       Pushes the new person into a vector of either
*           students or faculty.
*       Pushes the new accountNumber into a vector of
*           accountNumbers
****************************************************/

void Bank::createNewAccount() {
    cout << "Are you a ";
    cout << "1) Student ";
    cout << "or 2) Faculty Member?" << endl;
    cout << "Enter 1 or 2 to choose: ";
    int choice = 0;
    char makeDep;
    cin >> choice;
    while ((choice != 1) && (choice != 2)) {
        cout << endl;
        cout << "Invalid input. Please enter 1 or 2." << endl;
        cin >> choice;
    }

    if (choice == 1) {
        string fName, lName, dob, sAddress, country, maj, adv;
        int year = 0;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter first name then press enter" << endl;
        getline(cin, fName);
        cout << "Enter last name then press enter" << endl;
        getline(cin, lName);
        cout << "Enter date of birth (dd-mm-yyyy) then press enter" << endl;
        getline(cin, dob);
        cout << "Enter address then press enter" << endl;
        getline(cin, sAddress);
        cout << "Enter home country then press enter" << endl;
        getline(cin, country);
        string* countryPtr = findCountry(country);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter major then press enter" << endl;
        getline(cin, maj);
        cout << "Enter year (1 for freshman, 2 for sophomore, 3 for junior, 4 for senior)" << endl;
        cin >> year;
        cout << "Enter advisors name then press enter" << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, adv);
        cout << "Would you like to make deposit? (y/n): ";
        cin >> makeDep;
        if (makeDep == 'y' || makeDep == 'Y') {
            double amount;
            cout << endl;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            Student* tempStudent = new Student(fName, lName, dob, sAddress, countryPtr, maj, adv, year);
            //cout << *tempStudent
            AccountNumber* tempAccount = new AccountNumber(*tempStudent, amount);
            tempStudent->setAcctNum(tempAccount->getAccountNum());
            TotalMoneyInBank += amount;
            studentList.push_back(tempStudent);
            studentAccounts.push_back(tempAccount);
        }
        else {
            Student* tempStudent = new Student(fName, lName, dob, sAddress, countryPtr, maj, adv, year);
            //cout << *tempStudent;
            AccountNumber* tempAccount = new AccountNumber(*tempStudent);
            tempStudent->setAcctNum(tempAccount->getAccountNum());
            studentList.push_back(tempStudent);
            studentAccounts.push_back(tempAccount);
        }
    }


    if (choice == 2) {
        string fName, lName, dob, sAddress, country;
        int dep = 0;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter first name then press enter" << endl;
        getline(cin, fName);
        cout << "Enter last name then press enter" << endl;
        getline(cin, lName);
        cout << "Enter date of birth (dd-mm-yyyy) then press enter" << endl;
        getline(cin, dob);
        cout << "Enter address then press enter" << endl;
        getline(cin, sAddress);
        cout << "Enter home country then press enter" << endl;
        getline(cin, country);
        string* countryPtr = findCountry(country);
        cout << "Enter department (1 for Math, 2 for Bio, 3 for CompSci, 4 for Physics, 5 for Engineering)" << endl;
        cin >> dep;
        cout << "Would you like to make deposit? (y/n): ";
        cin >> makeDep;
        if (makeDep == 'y' || makeDep == 'Y') {
            double amount;
            cout << endl;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            Faculty* tempFaculty = new Faculty(fName, lName, dob, sAddress, countryPtr, dep);
            //cout << *tempStudent;
            AccountNumber* tempAccount = new AccountNumber(*tempFaculty,amount);
            tempFaculty->setAcctNum(tempAccount->getAccountNum());
            TotalMoneyInBank += amount;
            facultyList.push_back(tempFaculty);
            facultyAccounts.push_back(tempAccount);
        }
        else {
            Faculty* tempFaculty = new Faculty(fName, lName, dob, sAddress, countryPtr, dep);
            //cout << *tempStudent;
            AccountNumber* tempAccount = new AccountNumber(*tempFaculty);
            tempFaculty->setAcctNum(tempAccount->getAccountNum());
            facultyList.push_back(tempFaculty);
            facultyAccounts.push_back(tempAccount);
        }
    }
    return;
}



/*****************************************************
*   Function Name:  
*       findCountry(const string& country)
*   Params:
*       const string&
*   returns:
*       string*
*   What it does:
*       Takes a string and searches through a list of
*       countries to find a match. If a match is found
*       a pointer to the listed country is returned.
*       If a match is not found, user is prompted to
*       check spelling of entered country and try again.
********************************************************/

string* Bank::findCountry(const string& country) {
    string temp = country;
    for (int i = 0; i < temp.length(); i++) {
        char a = tolower(temp[i]);
        temp[i] = a;
    }
    //cout << "In findCountry(). " << "temp is: " << temp << endl;
    string* key;
    int correctLetters = 0;
    while (true) {
        for (int i = 0; i < 140; i++) {
            correctLetters = 0;
            if (temp.length() <= countries[i].length()) {
                for (int j = 0; j < temp.length(); j++) {
                    if (temp[j] == countries[i][j]) {
                        correctLetters++;
                    }
                }
            }
            if (temp.length() >= countries[i].length()) {
                for (int j = 0; j < countries[i].length(); j++) {
                    if (temp[j] == countries[i][j]) {
                        correctLetters++;
                    }
                }
            }
            if (correctLetters >= (temp.length() * 0.7)) {
                char correct;
                cout << "Found country: " << countries[i] << endl;
                cout << "Is this correct? (y/n)" << endl;
                cin >> correct;
                if (correct == 'y') {
                   key = &countries[i];
                   return key;
                }
            }
                
        }
        cout << "Could not find the country you entered. ";
        cout << "Please check spelling and try again." << endl;
        cout << "Home country: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, temp);
    }
    return 0;
}

/**************************************************************
*   INCOMPLETE FUNCTION
*   Function Name:
*       RunTheBank()
*   Params:
*       None
*   Returns:
*       void
*   What it does:
*       Main Driver of class Bank. When called, the user
*       is able to create a new bank account, access an
*       existing bank account, withdraw or deposit money,
*       and/or send money to another account.
***************************************************************/
void Bank::RunTheBank() {
    bool run = true;
    int choice = 0;
    cout << "Welcome to Mustang Bank" << endl;

    while (run) {
        cout << "Would you like to: " << endl << "1) Create account, ";
        cout << "2) Access existing account ";
        cout << "Or " << "0) Exit?" << endl << endl;
        cout << "Enter 0, 1, or 2 for your choice: ";
        cin >> choice;
        if (choice == 0) {
            run = false;
        }
        if (choice == 1) {
            createNewAccount();
        }
        if (choice == 2) {
            accessExistingAccount();
        }

    }
    return;
}

/*****************************************************
*   Function Name:
*       printAllCountries()
*   Params:
*       none
*   Returns:
*       void
*   What it does:
*       FOR TESTING PURPOSES
*       prints all countries contained
*       in the array countries[]
****************************************************/

void Bank::printAllCountries() {
    for (int i = 0; i < 140; i++) {
        cout << countries[i] << endl;
    }
    return;
}



/*****************************************************
*   Function Name:
*       printStudentList()
*   Params:
*       none
*   Returns:
*       void
*   What it does:
*       FOR TESTING PURPOSES
*       prints all Students contained in the
*       vector studentList
****************************************************/

void Bank::printStudentList() {
    for (int i = 0; i < studentList.size(); i++) {
        cout << *studentList[i];
    }
    return;
}




/*****************************************************
*   Function Name:
*       printStudentAccounts()
*   Params:
*       none
*   Returns:
*       void
*   What it does:
*       FOR TESTING PURPOSES
*       prints all account numbers, balances,
*       student information contained in the
*       vector studentAccounts
****************************************************/

void Bank::printStudentAccounts() {
    for (int i = 0; i < studentAccounts.size(); i++) {
        cout << "Account #" << studentAccounts[i]->getAccountNum();
        cout << endl;
        cout << "Balance: " << studentAccounts[i]->getBalance();
        cout << endl;
        cout << studentAccounts[i]->getStudent() << endl << endl;
    }
}

/*****************************************************
*   Function Name:
*       printStudentList()
*   Params:
*       none
*   Returns:
*       void
*   What it does:
*       FOR TESTING PURPOSES
*       prints all Students contained in the
*       vector facultyList
****************************************************/

void Bank::printFacultyList() {
    for (int i = 0; i < facultyList.size(); i++) {
        cout << *facultyList[i];
    }
    return;
}



/*****************************************************
*   Function Name:
*       printFacultyAccounts()
*   Params:
*       none
*   Returns:
*       void
*   What it does:
*       FOR TESTING PURPOSES
*       prints all account numbers, balances,
*       student information contained in the
*       vector facultyAccounts
****************************************************/

void Bank::printFacultyAccounts() {
    for (int i = 0; i < facultyAccounts.size(); i++) {
        cout << "Account #" << facultyAccounts[i]->getAccountNum();
        cout << endl;
        cout << "Balance: " << facultyAccounts[i]->getBalance();
        cout << endl;
        cout << facultyAccounts[i]->getFaculty();
    }
}




AccountNumber::AccountNumber() {
    acctNum = -1;
    moneyInAccount = 0.0;
    studentOwner = nullptr;
    facultyOwner = nullptr;
}


AccountNumber::AccountNumber(Faculty& fac) {
    acctCounter++;
    acctNum = acctCounter;
    moneyInAccount = 0.0;
    facultyOwner = &fac;
    studentOwner = nullptr;
}

AccountNumber::AccountNumber(Faculty& fac, double initDep) {
    acctCounter++;
    acctNum = acctCounter;
    moneyInAccount = initDep;
    facultyOwner = &fac;
    studentOwner = nullptr;
}


AccountNumber::AccountNumber(Student& stu) {
    acctCounter++;
    acctNum = (acctCounter + 1000);
    studentOwner = &stu;
    facultyOwner = nullptr;
}

AccountNumber::AccountNumber(Student& stu, double initDep) {
    acctCounter++;
    acctNum = (acctCounter + 1000);
    moneyInAccount = initDep;
    studentOwner = &stu;
    facultyOwner = nullptr;
}

int AccountNumber::getAccountNum() {
    return acctNum;
};

Student AccountNumber::getStudent() {
    return *studentOwner;
};

Faculty AccountNumber::getFaculty() {
    return *facultyOwner;
};

double AccountNumber::getBalance() {
    return moneyInAccount;
}
