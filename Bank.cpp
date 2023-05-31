#include "Bank.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <limits>
using namespace std;
template <typename T>
void p(T content){ //create general template
	cout<<"\t\t\t\t\t"<<content<<endl;
}
string acc;
const string admin = "1234";
inline int validate(){
	int var;
	cin>>var;
	while(!cin){
		cout<<"\n\t\t\t\t\tError: Invalid Input!\n\t\t\t\t\t=>";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cin>>var;
	}
	return var;
}
void Bank::OpenAccount(){
		ofstream File;
		File.open("account.txt", ios::app); // file is append
		p("\t\t\t\t\tEnter Account Number: ");
		cout<<"\t\t\t\t\t=>";
		Number = validate();
		while(Number<0){
			p("\t\t\t\t\tError! Enter a valid number.");
			p("\t\t\t\t\tEnter Account Number: ");
			cout<<"\t\t\t\t\t=>";
			cin>>Number;
		}
		p("\t\t\t\t\tEnter Account Name: ");
		cout<<"\t\t\t\t\t=>";
		cin.ignore();
		getline(cin, Name);
		p("\t\t\t\t\tEnter Account Balance: ");
		cout<<"\t\t\t\t\t=>";
		Balance = validate();
		while(Balance<=0){
			p("\t\t\t\t\tError! Enter a valid amount");
			p("\t\t\t\t\tEnter Account Balance: ");
			cout<<"\t\t\t\t\t=>";
			cin>>Balance;
		}
		File<<Number<<", "<<Name<<", "<<Balance<<endl;
		File.close();
		p("\t\t\t\t\tAccount has been created successfully!");
}

void Bank::ShowAccount(){
		
		ifstream File;
		File.open("account.txt");
		string account;
		cout<<"\n\t\t\t\t\t=======================\n";
		cout<<"\t\t\t\t\tNumber\tName\tBalance\n";
		cout<<"\t\t\t\t\t=======================\n";
		while(getline(File, account)){
			cout<<"\t\t\t\t\t";
			cout<<" ";
			for (int i = 0 ; i < account.length() ; i++){
				if (account[i]==','){
					cout<<"  |  ";
				}
				else{
					cout<<account[i];
				}
			}
			cout<<endl;
			account.clear();
		}
		File.close();
}

int Bank::Deposit(){
	int amount;
	acc = "no";
	Search();
	if (acc=="no"){
		p("\t\t\t\t\tNo such account exists...");
		return 0;
	}
	string str_balance;
	str_balance.clear();
	for (int i = 0 ; i < acc.length(); i++){
		if (acc[i] == ',')
			str_balance.clear();
		else
			str_balance += acc[i];
	}
	cout<<"\t\t\t\t\tBalance: "<<str_balance<<endl;
	Balance = stoi(str_balance);
	p("\t\t\t\t\tEnter Ammount: ");
	cout<<"\t\t\t\t\t=>";
	amount = validate();
	while (amount < 1){
		p("\t\t\t\t\tError! Please enter positive amount.");
		p("\t\t\t\t\tEnter Ammount: ");
		cout<<"\t\t\t\t\t=>";
		amount = validate();
	}
	Balance += amount;
	cout<<"\t\t\t\t\tNew Balance: "<<Balance<<endl;
	p("\n\t\t\t\t\tAmount Deposited Successfully!");
	fstream File("account.txt");
	fstream Temp;
	Temp.open("temp.txt", ios::app);
	string new_acc;
	new_acc.clear();
	string temp_account;
	while(!File.eof()){
		getline(File, temp_account);
		if (temp_account == acc){
			int count = 0;
			for (int i = 0; (i < acc.length() && count < 2) ; i++ ){
				new_acc += acc[i];
				if (acc[i]==','){
					count++;
				}
			}
			new_acc += to_string(Balance);
			Temp<<new_acc<<endl;
		}
		else{
			Temp<<temp_account<<endl;
		}
	}
	File.close();
	Temp.close();
	remove("account.txt");
	rename("temp.txt","account.txt");
}

int Bank::Withdrawal(){
	int amount;
	acc = "no";
	Search();
	if (acc=="no"){
		p("\t\t\t\t\tNo such account exists...");
		return 0;
	}
	string str_balance;
	str_balance.clear();
	
	for (int i = 0 ; i < acc.length(); i++){
		if (acc[i] == ',')
			str_balance.clear();
		else
			str_balance += acc[i];
	}
	cout<<"\t\t\t\t\tBalance: "<<str_balance<<endl;
	Balance = stoi(str_balance);
	p("\t\t\t\t\tEnter Amount: ");
	cout<<"\t\t\t\t\t=>";
	amount = validate();
	while(amount<=0){
		p("\t\t\t\t\tError: Incorrect Value");
		p("\t\t\t\t\tEnter Amount: ");
		cout<<"\t\t\t\t\t=>";
		amount= validate();
	}
	if (amount <= Balance){
		Balance -= amount;
		cout<<"\t\t\t\t\tNew Balance: "<<Balance<<endl;
		p("\n\t\t\t\t\tAmount Withdrawn Successfully.");
	}
	else{
		p("\n\t\t\t\t\tNo Enough Balance in the Account");
		Withdrawal();
	}
	fstream File("account.txt");
	fstream Temp;
	Temp.open("temp.txt", ios::app);
	string new_acc;
	new_acc.clear();
	string temp_account;
	while(!File.eof()){
		getline(File, temp_account);
		if (temp_account == acc){
			int count = 0;
			for (int i = 0; (i < acc.length() && count < 2) ; i++ ){
				new_acc += acc[i];
				if (acc[i]==','){
					count++;
				}
			}
			new_acc += to_string(Balance);
			Temp<<new_acc<<endl;
		}
		else{
			Temp<<temp_account<<endl;
		}
	}
	File.close();
	Temp.close();
	remove("account.txt");
	rename("temp.txt","account.txt");
}

void Bank::Search(){
	int acc_num;
	acc = "no";
	p("\n\t\t\t\t\tEnter Account Number: ");
	cout<<"\t\t\t\t\t=>";
	acc_num = validate();
	while(acc_num < 1){
		cout<<"\t\t\t\t\tError: Only Enter Positive Numbers\n";
		p("\n\t\t\t\t\tEnter Account Number: ");
		cout<<"\t\t\t\t\t=>";
		acc_num = validate();
	}
	
	ifstream File;
	File.open("account.txt");
	string account;
	string GetAccNum;
	while(getline(File, account)){
		GetAccNum.clear();
		for (int i = 0 ; i < account.length(); i++){
			if (account[i] != ','){
				GetAccNum += account[i];
			}
			else{
				break;
			}
		}
		if (to_string(acc_num)== GetAccNum){
			acc = account;
			break;
		}
	}
	
	p("\t\t\t\t\t=======================");
	p("\t\t\t\t\tNumber\tName\tBalance");
	p("\t\t\t\t\t=======================");
	cout<<"\t\t\t\t\t";
	for (int i = 0 ; i < account.length() ; i++){
				if (account[i]==','){
					cout<<"  |  ";
				}
				else{
					cout<<account[i];
				}
	}
	cout<<endl;
}

inline void Menu(){
	printAscii();
	cout<<"\t\t\t\t\t1) Open Account"<<endl
		<<"\t\t\t\t\t2) Show Account"<<endl
		<<"\t\t\t\t\t3) Deposit Amount"<<endl
		<<"\t\t\t\t\t4) Withdraw Amount"<<endl
		<<"\t\t\t\t\t5) Search Account"<<endl
		<<"\t\t\t\t\t0) Exit"<<endl
		<<"\t\t\t\t\t=>";
}

int bank(){
	int what;
	Bank account;
	Menu();
	what = validate();
	while(what<0 || what>5){
		system("CLS");
		p("\n\n\n\n\t\t\t\t\tError! invalid option selected.");
		Menu();
		cin>>what;
	}
	system("CLS");
	switch(what){
		case 1:
			p("\n\n\t\t\t\t\t   OPEN ACCOUNT");
			account.OpenAccount();
			break;
		case 2:
			p("\n\n\t\t\t\t\t   ALL BANK ACCOUNT");
			account.ShowAccount();
			break;
		case 3:
			p("\n\n\t\t\t\t\t   DEPOSIT AMOUNT");
			account.Deposit();
			break;
		case 4:
			p("\n\n\t\t\t\t\t   WITHDRAW AMOUNT");
			account.Withdrawal();
			break;
		case 5:
			p("\n\n\t\t\t\t\t   SEARCH AMOUNT");
			account.Search();
			break;
		case 0:
			p("\n\n\t\t\t\t\tLogging Out.... Thanks for using Bank :)");
			return 0;
		default:
			p("\n\n\t\t\t\t\t Something went wrong!");
	}
	bank();
}

string getbpass(){
	string password = ""; 
    char pass;
    while(pass != 13 ) 
    {
         pass = getch();
         if (pass == 8){
         	continue;
		 }
         else if (pass != 13){
		 	cout<<"*"; 
         	password.push_back(pass);
		}
	}
    return password;
}

void printAscii(){
	string line="";
	ifstream inFile;
	inFile.open("smartbankart.txt");
	if (inFile.is_open())
	{
		while (getline(inFile,line))
		{
			cout<<line<<endl;
		}
	}
	else 
	{
	cout<<"\n\n\n\n\n\t\t\t\t\t-------------------------\n";
	cout<<"\t\t\t\t\tWelcome to Smart Bank\n";
	cout<<"\t\t\t\t\t-------------------------\n";
	}
	inFile.close();
}

int mainBank(){
	system("color 0C");
	Bank acc;
	string get_pass;
	system("CLS");
	usebank:
			p("\n\n\n\n\t\t\t\t\tLOGIN IN");
			p("\n\n\t\t\t\t\tEnter Admin Password (0 to Exit): ");
			cout<<"\t\t\t\t\t=>";
			get_pass = getbpass();
			if (get_pass == admin){
				system("CLS");
				p("\n\t\t\t\t\tYou are Logged in!!!");
				bank();
				return 0;
			}
			else if (get_pass == "0"){
				p("\n\t\t\t\tExiting....");
				return 0;
			}
			else{
				system("CLS");
				p("\n\n\n\n\n\t\t\t\t\tThe Password is incorrect");
				goto usebank;
			}
	mainBank();
	return 0;
}
