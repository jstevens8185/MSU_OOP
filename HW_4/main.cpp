#include<iostream>
#include<string>
#include "person.h"
#include "bank.h"

using namespace std;

int AccountNumber::acctCounter = 0;


/////////////////////////////////////////////////
//	STILL NEEDED:
//		functionality to:
//		-withdraw
//		-deposit
//		-send money to another account
//		-view balance
/////////////////////////////////////////////////

int main() {
	//string UnitedStates = "united states";
	//string* usa = &UnitedStates;
	//Student Jered("Jered", "Stevens", "10-20-1998", "3004 Barrywood Drive", usa, "CompSci", "Tina Johnson", 3);
	//cout << Jered;

	Bank bank;
	bank.createNewAccount();
	bank.printStudentAccounts();
}