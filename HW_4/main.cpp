#include<iostream>
#include <string>
#include "person.h"
#include "bank.h"

using namespace std;

int AccountNumber::acctCounter = 0;


int main() {
	Bank bank;
	bank.createNewAccount();
	bank.printStudentAccounts();
}