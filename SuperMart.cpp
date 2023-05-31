#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include <limits>
#include "SuperMart.h"
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

string pro;
template <typename T>
void p(T content){ //create general template
	cout<<content<<endl;
}
const string admin = "1234";

fstream fp;

 
void product::add_product(){
	ofstream File;
		File.open("product.txt", ios::app); // file is append
		p("\n\n\n\n\t\t\t\t\tEnter Product Number: ");
		cout<<"\t\t\t\t\t=>";
		product_number = validate();
		while(product_number<0){
			p("\t\t\t\t\tError! Enter a valid number.");
			p("\t\t\t\t\tEnter Product Number: ");
			cout<<"\t\t\t\t\t=>";
			cin>>product_number;
		}
		p("\t\t\t\t\tEnter Product Name: ");
		cout<<"\t\t\t\t\t=>";
		cin.ignore();
		getline(cin, product_name);
		p("\t\t\t\t\tEnter Product Price: ");
		cout<<"\t\t\t\t\t=>";
		cin>>product_price;
		while(product_price<=0){
			p("\t\t\t\t\tError! Enter a valid amount");
			p("\t\t\t\t\tEnter Product Price: ");
			cout<<"\t\t\t\t\t=>";
			cin>>product_price;
		}
		File<<product_number<<", "<<product_name<<", "<<product_price<<endl;
		File.close();
		p("\t\t\t\t\tProduct has been created successfully!.");
}
 
 
void product::show_all_product()
{
	ifstream File;
		File.open("product.txt");
		string product;
		cout<<"\n\t\t\t\t\t\t=======================\n";
		cout<<"\t\t\t\t\t\tP.NO.\tNAME\tPRICE\n";
		cout<<"\t\t\t\t\t\t=======================\n";
		while(getline(File, product)){
			cout<<"\t\t\t\t\t\t";
			cout<<" ";
			for (int i = 0 ; i < product.length() ; i++){
				if (product[i]==','){
					cout<<"  |  ";
				}
				else{
					cout<<product[i];
				}
			}
			cout<<endl;
		}
		File.close();
}
 
 
void product::display_record(string prod_num)
{
	while(!cin){
		cout<<"\t\t\t\t\tError: Invalid Input.\n";
		cin.ignore();
		cin.clear();
		p("\n\t\t\t\t\tEnter Product Number: ");
		cout<<"\t\t\t\t\t=>";
		cin>>prod_num;
	}
	
	ifstream File;
	File.open("product.txt");
	string Product;
	string GetProNum;
	while(getline(File, Product)){
		GetProNum.clear();
		for (int i = 0 ; i < Product.length(); i++){
			if (Product[i] != ','){
				GetProNum += Product[i];
			}
			else{
				break;
			}
		}
		if (prod_num == GetProNum){
			pro = Product;
			break;
		}
	}
	
	p("\t\t\t\t\t=======================");
	p("\t\t\t\t\tNumber\tName\tBalance");
	p("\t\t\t\t\t=======================");
	cout<<"\t\t\t\t\t";
	for (int i = 0 ; i < Product.length() ; i++){
				if (Product[i]==','){
					cout<<"  |  ";
				}
				else{
					cout<<Product[i];
				}
	}
	cout<<endl;
}

void display_invoice(string prod_num, int quan){
	while(!cin){
		cout<<"\t\t\t\t\tError: Invalid Input.\n";
		cin.ignore();
		cin.clear();
		p("\n\t\t\t\t\tEnter Product Number: ");
		cout<<"\t\t\t\t\t=>";
		cin>>prod_num;
	}
	
	ifstream File;
	File.open("product.txt");
	string Product;
	string GetProNum;
	while(getline(File, Product)){
		GetProNum.clear();
		for (int i = 0 ; i < Product.length(); i++){
			if (Product[i] != ','){
				GetProNum += Product[i];
			}
			else{
				break;
			}
		}
		if (prod_num == GetProNum){
			pro = Product;
			break;
		}
	}
	
	p("\t\t\t\t\t==============================");
	p("\t\t\t\t\tP.No.\tName\tBalance\tQuantity");
	p("\t\t\t\t\t==============================");
	cout<<"\t\t\t\t\t";
	int comma = 0;
	for (int i = 0 ; i < Product.length() ; i++){
				if (Product[i]==','){
					cout<<"  |  ";
					comma++;
				}
				else{
					cout<<Product[i];
				}
	}
	if (pro != "no") cout<<"  |  "<<quan<<endl;
}
void product::place_order()
{
	int order_arr[50],quan[50],c=0;
	float amt,damt,total=0;
	char ch='Y';
	show_all_product();
	cout<<"\n\t\t\t\t<<<==========================================>>>";
	cout<<"\n\t\t\t\t\t\t PLACE YOUR ORDER";
	cout<<"\n\t\t\t\t<<<==========================================>>>\n";
	do{
		cout<<"\n\n\t\t\t\t\t\tEnter The Product #: ";
		order_arr[c]=validate();
		display_record(to_string(order_arr[c]));
		cout<<"\n\t\t\t\t\t\tQuantity: ";
		quan[c]= validate();
		c++;
		
		cout<<"\n\t\t\t\t\t\t Do You Want To Order Another Product ? (y/n)";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');
	cout<<"\n\n\t\t\t\t\t\t Thank You...";
	getchar();
	system("cls");
	cout<<"\n\n\t\t\t********************************INVOICE********************************\n";
	for(int x=0;x<c;x++)
	{
		pro = "no";
		display_invoice(to_string(order_arr[x]), quan[x]);
		string str_balance;
		str_balance.clear();
		if (pro=="no"){
			p("\t\t\t\t\tNo such product exists...");
			quan[x] = 0;
			continue;
		}
		for (int i = 0 ; i < pro.length(); i++){
			if (pro[i] == ',')
				str_balance.clear();
			else
				str_balance += pro[i];
		}
		total += stoi(str_balance) * quan[x];
	}
	cout<<"\n\n\t\t\t\t\t\tTOTAL = "<<total<<endl;
	system("PAUSE");
	system("CLS");
}

string getpass(){
	string password = ""; 
    char pass;
    while(pass != 13 ) 
    {
         pass = getch();
         if (pass == 8){
         	continue;
		 }
         if (pass != 13){
		 	cout<<"*"; 
         	password.push_back(pass);
		}
	}
    return password;
}

int admin_menu()
{
	product prod;
	
	int option;
	cout<<"\n\n\n\n\t\t\t\t\t<<<==========================================>>>";
	cout<<"\n\t\t\t\t\t\tPress 1 to CREATE PRODUCT";
	cout<<"\n\t\t\t\t\t\tPress 2 to DISPLAY ALL PRODUCTS";
	cout<<"\n\t\t\t\t\t\tPress 3 to SEARCH PRODUCT ";
	cout<<"\n\t\t\t\t\t\tPress 4 to GO BACK TO MAIN MENU";
	cout<<"\n\t\t\t\t\t<<<==========================================>>>";
 
	cout<<"\n\n\t\t\t\t\tOption: ";
	cin>>option;string Prod_num;
	switch(option)
	{
		case 1: system("cls");
				prod.add_product();
				break;
				
		case 2: system("cls");
				prod.show_all_product();
				break;
				
		case 3:
				system("cls");
				p("\n\t\t\t\t\tEnter Product Number: ");
				cout<<"\t\t\t\t\t=>";
				cin>>Prod_num;
				prod.display_record(Prod_num);
				break;	
		case 4: system("cls");
				return 0;
				break;
		
		default:
			admin_menu();
			break;
	}
	admin_menu();
}

void printAScii(){
	string line="";
	ifstream inFile;
	inFile.open("smartmartart.txt");
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
	cout<<"\t\t\t\t\tWelcome to Smart Mart\n";
	cout<<"\t\t\t\t\t-------------------------\n";
	}
	inFile.close();
}


int mainMart(){
	system("cls");
	system("color B4");
	int option;
	product prod;
	for(;;){ 
		
		printAScii();
		cout<<"\n\t\t\t\t\t\t1. CUSTOMER";
		cout<<"\n\t\t\t\t\t\t2. ADMINISTRATOR";
		cout<<"\n\t\t\t\t\t\t3. EXIT";
		cout<<"\n\t\t\t\t\t<<<====================================>>>";
		
		cout<<"\n\t\t\t\t\tOption: ";
		cin>>option;
		string get_pass;
		switch(option)
		{
			case 1: system("cls");
					prod.place_order();
					break;

			case 2: 				
				system("cls");
				
				usebank:
						p("\n\n\n\n\t\t\t\t\tLOGIN IN");
						p("\n\n\t\t\t\t\tEnter Admin Password (0 to Exit): ");
						cout<<"\t\t\t\t\t=>";
						get_pass = getpass();
						if (get_pass == admin){
							system("CLS");
							p("\n\t\t\t\t\tYou are Logged in!!!");
						}
						else if (get_pass == "0"){
							p("\nExiting....");
							return 0;
						}
						else{
							system("CLS");
							p("\n\n\n\n\n\t\t\t\t\tThe Password is incorrect");
							goto usebank;
						}
						admin_menu();
				break;
						
			case 3: 
					system("CLS");
					cout<<"\n\t\t\t\t\t<<<=============================>>>";
					cout<<"\n\t\t\t\t\t\tExiting SuperMart....";
					cout<<"\n\t\t\t\t\t<<<=============================>>>";
					return 0;
			default :
					cout<<"Invalid Input...\n";
		}
	}
	return 0;
}
