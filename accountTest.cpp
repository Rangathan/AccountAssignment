
#include <iostream>
#include <string>
#include "account.h"


using namespace std;

int main()
{
	//std::cout << "Create 3 accounts and print them using account's toString() method:\n";
	// 1- create 3 accounts for 3 people as following:
	cout << "Three new accounts for the Bank\n";
	DollarAmount thebalance(250000);
	Account janeChequingAccount("Jane Doe", thebalance, Account::AccountType::chequing);
	cout << "Chequing " << janeChequingAccount.toString() << endl;
	Account janeSavingAccount("Jane Doe", thebalance, Account::AccountType::saving);
	cout << "Saving " << janeSavingAccount.toString() << endl;
	Account aliChequingAccount("Ali Barooti", thebalance, Account::AccountType::chequing);
	cout << "Chequing " << aliChequingAccount.toString() << endl;
		// 2- Name=Jane Doe, amount =  $2500,  type = Saving
		// 3- Name = Ali Barooti, amount =  $2500, type = Checking

	//std::cout << "\nCompare interest accumulation yearly, monthly and daily styles:\n";
	// In the following we want to compare interest accumulation yearly vs monthly vs daily for the same amount:
	// 2- Add interest as following: 
		// 1- For Jane's checking account: call CompoundInterestYearly. yearly Interest rate 2.45%, for 10 years, 
	cout << "Compounding interest for them \n";

	janeChequingAccount.CompoundInterestYearly(245, 100, 10);
				// Then print Jane checking account using toString() method in Account class
	cout << "Jane's Chequing account after Yearly Interest is added: " << janeChequingAccount.toString();
		// 2- For Jane's saving account: call CompoundInterestMonthly. yearly Interest rate 2.45%, for 10 years,
	janeSavingAccount.CompoundInterestMonthly(245, 100, 120);
				// Then print Jane saving account using toString() method in Account class
	cout << "Jane's Saving account after Monthly Interest is added: " << janeSavingAccount.toString();
		// 1- For Ali's checking account: call CompoundInterestDaily. yearly Interest rate 2.45%, for 10 years, 
	aliChequingAccount.CompoundInterestDaily(245, 100, 3650);
				// Then print Ali account using toString() method in Account class
	cout << "Ali's Chequing account after Daily interest is added: " << aliChequingAccount.toString();

	std::cout << "\nTransfer $550.65 from Jane's saving account to her checking account:\n";
	// In the following we practice transferring money from one account to another:
	// 3- Withdraw $550.65 from Jane's saving account and deposit in her checking account.
	janeSavingAccount.withdraw(550, 65);
	//		You must use account's methods withdraw(dollar, cents) and deposit(dollar, cents)
	janeChequingAccount.deposit(550, 65);
			//Finally  print the 2 accounts after the transfer
	cout << "Jane's Chequing account after Deposit is added: " << janeChequingAccount.toString();
	cout << "Jane's Saving account after Withdraw is minused: " << janeSavingAccount.toString();

	
	
	return 0;
}

