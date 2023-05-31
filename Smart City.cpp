#include <iostream>
#include <windows.h>
#include <limits>
#include "Bank.h"
#include "hospital.h"
#include "University.h"
#include "SuperMart.h"
#include <fstream>

using namespace std;
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

void printascii(){
	string line="";
	ifstream inFile;
	inFile.open("smartcityart.txt");
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
	cout<<"\t\t\t\t\tWelcome to Smart City\n";
	cout<<"\t\t\t\t\t-------------------------\n";
	}
	inFile.close();
}

int main(){
	system("color 0C");
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	printascii();
//	cout<<"\t\t\t\t\t<============================>\n\n\n";
	cout<<"\t\t\t\t\t1- Smart Banking System"<<endl;
	cout<<"\t\t\t\t\t2- Smart Hospital"<<endl;
	cout<<"\t\t\t\t\t3- Smart University"<<endl;
	cout<<"\t\t\t\t\t4- Smart Shopping Mart"<<endl;
	cout<<"\t\t\t\t\t5- Exit"<<endl;
	cout<<"\t\t\t\t\t=>";
	
	int what;
	
	what  = validate();
	while(what < 1 || what > 5){
		cout<<"\n\t\t\t\t\tError: Invalid Option Seclected!\n\t\t\t\t\t=>";
		cin>>what;
	}
	
	switch (what){
		case 1:
			mainBank();
			break;
		case 2:
			mainHospital();
			break;
		case 3:
			mainUniversity();
			break;
		case 4:
			mainMart();
			break;
		case 5:
			cout<<"\t\t\t\t\tThanks for visiting the City\n";
			exit(0);
		default:
			cout<<"\t\t\t\t\tSomething went wrong!\n";
	}
	main();
	return 0;
}
