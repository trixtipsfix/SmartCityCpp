#include <iostream>
using namespace std;

class Bank{
	int Number;
	string Name;
	long int Balance;
public:	
	void OpenAccount();
	void ShowAccount();
	int Deposit();
	int Withdrawal();
	void Search();
};
int mainBank();
void Menu();
int bank();
void printAscii();

