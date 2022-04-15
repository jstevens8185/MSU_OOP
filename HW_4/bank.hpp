#pragma once
#include "bank.h"
#include <iostream>
#include <string>
#include "person.h"
#include "student.h"
#include <vector>
#include <fstream>
using namespace std;

Bank::Bank(){
    TotalMoneyInBank = 0;
    buildCountryList();   
}

void Bank::buildCountryList(){
        ifstream in;
        in.open("countryList.dat");
        int count = 0;
        string line;
        while(getline(in, line))
        {
            for(int i = 0; i < sizeof(line); i++){
                char a = tolower(line[i]);
                line[i] = a;
            }

            countries[count] = line;
            count++;
        }

        return;
}

void Bank::createNewAccount(){
    cout << "Are you a: " << endl;
    cout << "1) Student" << endl;
    cout << "or\n2) Faculty Member?" << endl;
    cout << "Enter 1 or 2 to choose: ";
    int choice = 0;
    cin >> choice;
    while((choice != 1) && (choice != 2)){
        cout << endl;
        cout << "Invalid input. Please enter 1 or 2." << endl;
        cin >> choice;
    }

    if(choice = 1){
        string fName, lName, dob, sAddress, country, maj, adv;
        int year;
        cout << "Enter first name then press enter" << endl;
        cin >> fName;
        cout << "Enter last name then press enter" << endl;
        cin >> lName;
        cout << "Enter date of birth (dd-mm-yyyy) then press enter" << endl;
        cin >> dob;
        cout << "Enter address then press enter" << endl;
        cin >> sAddress;
        cout << "Enter home country then press enter" << endl;
        cin >> country;
        cout << "Enter major then press enter" << endl;
        cin >> maj;
        cout << "Enter advisors name then press enter" << endl;
        cin >> adv;
    }
}

void Bank::RunTheBank(){
    bool run = true;
    int choice = 0;
    cout << "Welcome to Mustang Bank" << endl;

    while(run){
        cout << "Would you like to: " << endl << "1) Create account" << endl;
        cout << "Or" << endl << "2) Access existing account" << endl << endl;
        cout << "Enter 1 or 2 for your choice: ";
        cin >> choice;
        if(choice == 1){
            createNewAccount();
        }
    }
}

void Bank::printAllCountries(){
    for(int i = 0; i < 140; i++){
        cout << countries[i] << endl;
    }
    return;
}