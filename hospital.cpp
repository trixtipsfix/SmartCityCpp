#include "hospital.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <limits>

using namespace std;
const string admin = "1234";
template <typename T>
void p(T content){ //create general template
	cout<<content<<endl;
}
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
string getpassh(){
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

int password::passwordprotect(){
			string get_pass;
			usebank:
			
			p("\n\n\n\n\t\t\t\t\tLOGIN IN");
			p("\n\n\t\t\t\t\tEnter Admin Password (0 to Exit): ");
			cout<<"\n\t\t\t\t\t=> ";
			get_pass = getpassh();
			if (get_pass == admin){
				system("CLS");
				p("\n\t\t\t\t\tYou are Logged in!!!");
				
			}
			else if (get_pass == "0"){
				p("\nExiting....");
				mainHospital();
			}
			else{
				system("CLS");
				p("\n\n\n\n\n\t\t\t\t\tThe Password is incorrect");
				goto usebank;
			}
}





string doctor::getSpec(){
	string sp;
	cout<<"\n\n\t\t\t\t\t1.GENERAL MEDICINE"<<endl;
	cout<<"\t\t\t\t\t2.NEUROLOGY"<<endl;
	cout<<"\t\t\t\t\t3.ONCOLOGY"<<endl;
	cout<<"\t\t\t\t\t4.CARDIOLOGY"<<endl;
	cout<<"\t\t\t\t\t5.SURGICAL"<<endl;
	cout<<"\t\t\t\t\t6.DERMATOLOGY"<<endl;	
	int s;
	cout<<"\t\t\t\t\t";
	s = validate();
	while(s < 1 || s > 6){
		cout<<"\n\t\t\t\t\tError: Enter a valid option(1-6)\n=>";
		cout<<"\t\t\t\t\t";
		cin>>s;
	}
	switch(s){
		
		case 1:{
			sp="\t\t\t\t\tGENERAL_MEDICINE";
			break;
		}
		case 2:{
			sp="\t\t\t\t\tNEUROLOGY";
			break;
		}
		case 3:{
			sp="\t\t\t\t\tONCOLOGY";
			break;
		}
		case 4:{
			sp= "\t\t\t\t\tCARDIOLOGY";
			break;
		}
		case 5:{
			sp= "\t\t\t\t\tSURGICAL";
			break;
		}
		case 6:{
			sp= "\t\t\t\t\tDERMATOLOGY";
			break;
		}
		default:{
			cout<<"\n\t\t\t\t\tEnter a valid option(1-6)";
			getSpec();
		}
	}
	return sp;
}


//add doctor to database
void addDoc(){
	    doctor d;
	    cout<<"\n\n\n\t\t\t\t\tFill up the following details"<<endl;
	    cout<<"\n\t\t\t\t\tID: ";
	    d.d_ID = validate();
   		cout<<"\t\t\t\t\tFirst Name: ";
   		cin>>d.d_fname;
   		cout<<"\t\t\t\t\tLast Name: ";
   		cin>>d.d_lname;
   		cout<<"\t\t\t\t\tAge: ";
   		d.d_age = validate();
   		cout<<"\t\t\t\t\tChoose Qualification among the following:\n\t\t\t\t\t1.MBBS\n\t\t\t\t\t2.MD"<<endl;
   		int q;
   		cout<<"\t\t\t\t\t=> ";
   		q = validate();
   		while(q < 1 || q > 2){
		cout<<"\n\t\t\t\t\tError: Enter a valid option(1-2)\n\t\t\t\t\t=>";
		q = validate();
		}
   		if(q==1)
   			d.qual="\t\t\t\t\tMBBS";
		else d.qual="\t\t\t\t\tMD";
		cout<<"\t\t\t\t\tChoose Specialization among the following: ";
		string spec=d.getSpec();
		cout<<"\t\t\t\t\tExperience (in Years): ";
		d.experience = validate();
		cout<<"\t\t\t\t\tCity: ";
		cin>>d.d_city;
		system("cls");
		
		fstream fileObj;
		fileObj.open("doctor.txt", ios::app);
		fileObj<<d.d_ID<<endl<<d.d_fname<<endl<<d.d_lname<<endl<<d.d_age<<endl<<d.qual<<endl<<spec<<endl<<d.experience<<endl<<d.d_city<<endl;
		fileObj.close();
		
	//after saving doc info
	
	cout<<"\n\n\n\t\t\t\tNew Doctor Profile created successfully!";
	cout<<"\n\n\n\t\t\t\tEnter 1 to return to Doctor Database\n\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t\t=> ";
	c= validate();
	if(c==1){
	  system("cls");
	  getDoctorDatabase();
	}

	else{
		cout<<"\t\t\t\t\tExiting....";
		getDoctorDatabase();
	}
}

//Display Doctor Function
int displayDoc(){
	int x;
	cout<<"\n\n\n\t\t\t\tEnter the ID of doctor you are looking for: ";
	x= validate();
	
	ifstream file;
	file.open("doctor.txt",ios::out|ios::in);
	file.seekg(0);		//gives position 0 in the file(starting of file)
	
	int ID,age,exp,count=0;
	string fname,lname,ci,qua,spe;
	
	while(file >> ID >> fname >> lname >>age >>qua >> spe >>exp >> ci)   
	{

		if(ID==x)
		{
		cout<<"\t\n\n\t\t\t\t1.ID: "<<ID<<endl<<"\t\t\t\t2.First Name: "<<fname<<endl<<"\t\t\t\t3.Last Name: "<<lname<<endl<<"\t\t\t\t4.Age: "<<age<<endl<<"\t\t\t\t5.Qualification: "<<qua<<endl<<"\t\t\t\t6.Specialization: "<<spe<<endl<<"\t\t\t\t7.Experience: "<<exp<<endl<<"\t\t\t\t8.City: "<<ci<<endl<<endl;
		count++;
		}
	}
	file.close();
	if (count==0)
			cout<<"\n\t\t\t\t\tNo matching records found!"<<endl;

	cout<<"\n\n\t\t\t\tEnter 1 to return to Doctor Database\n\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t\t=> ";
	c= validate();
	if(c==1){
	  system("cls");
	  getDoctorDatabase();
	}

	else{
		system("CLS");
		return 0;
	}
	
}

int dispDatabase(){
	fstream fileobj("doctor.txt");
	fileobj.seekg(0);	//gives position 0 in the file(starting of file)
	
	cout<<"\n\n\t\t\t\tDOCTOR DATABASE\n";
	int age,exp,count=0;
	string ID,fname,lname,ci,qua,spe;
	
	while(fileobj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci){	
		count++;
		cout<<"\n\n\t\t\t\tDoctor Profile "<<count<<" :"<<endl;
		cout<<"\n\n\t\t\t\t1.ID:"<<ID<<endl<<"\t\t\t\t2.First Name:"<<fname<<endl<<"\t\t\t\t3.Last Name:"<<lname<<endl<<"\t\t\t\t4.Age:"<<age<<endl<<"\t\t\t\t5.Qualification:"<<qua<<endl<<"\t\t\t\t6.Specialization:"<<spe<<endl<<"\t\t\t\t7.Experience:"<<exp<<endl<<"\t\t\t\t8.City:"<<ci<<endl<<endl;
	}

	if(count==0){
		cout<<"\n\t\t\t\t\tNo matching records found!"<<endl;
	 	exit(0);
		cout<<"\n\n\t\t\t\t\tEnter 1 to return to Doctor Database\n\t\t\t\t\tEnter 2 to Exit."<<endl;
		int c;
		cout<<"\n\t\t\t\t\t=> ";
		c= validate();
		if(c==1){
		  system("cls");
		  getDoctorDatabase();
		}
		else{
			system("CLS");
			return 0;
		} 	
	}
	system("PAUSE");
	system("CLS");
	getDoctorDatabase();
}

// This function shows Number of total doctors

void numberofDocs(){
	fstream fileobj("doctor.txt");
	fileobj.seekg(0);
	int age,exp,count=0;
	string ID,fname,lname,ci,qua,spe;
	while(fileobj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{	
	count++;
	}
	
	cout<<"\n\n\t\t\t\tThe no. of doctors in the hospital= "<<count<<endl<<endl;
	
	cout<<"\n\n\t\t\t\tEnter 1 to return to Doctor Database\n\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t=> ";
	c= validate();
	if(c==1)
	{
	  system("cls");
	  getDoctorDatabase();
	}

	else
	  exit(0);
	  
}

string patient::getDept(){
	string sp;
	cout<<"\n\n\t\t\t\t\t1.GENERAL MEDICINE"<<endl;
	cout<<"\t\t\t\t\t2.NEUROLOGY"<<endl;
	cout<<"\t\t\t\t\t3.ONCOLOGY"<<endl;
	cout<<"\t\t\t\t\t4.CARDIOLOGY"<<endl;
	cout<<"\t\t\t\t\t5.SURGICAL"<<endl;
	cout<<"\t\t\t\t\t6.DERMATOLOGY"<<endl;	
	int s;
	cout<<"\t\t\t\t\t=>";
	s= validate();
	while(s < 1 || s > 6){
		cout<<"\n\t\t\t\t\tError: Enter a valid option(1-6)\n\t\t\t\t\t=>";
		cin>>s;
	}
	switch(s){
		
		case 1:{
			cout<<"\t\t\t\t\t";
			sp="GENERAL_MEDICINE";
			break;
		}
		case 2:{
			cout<<"\t\t\t\t\t";
			sp="NEUROLOGY";
			break;
		}
		case 3:{
			cout<<"\t\t\t\t\t";
			sp="ONCOLOGY";
			break;
		}
		case 4:{
			cout<<"\t\t\t\t\t";
			sp= "CARDIOLOGY";
			break;
		}
		case 5:{
			cout<<"\t\t\t\t\t";
			sp= "SURGICAL";
			break;
		}
		case 6:{
			cout<<"\t\t\t\t\t";
			sp= "DERMATOLOGY";
			break;
		}
		default:{
			cout<<"\n\t\t\t\t\tEnter a valid option(1-6)";
			getDept();
		}
	}
	return sp;
}

// this function gets a doctor for patient 
void getDoctor(){
	patient p;
	string dept;
	
	cout<<"\n\n\n\t\t\tEnter the kind of specialization you are looking for:"<<endl;
	dept=p.getDept();
	system("cls");
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	cout<<"\n\t\t\tThe doctors available with "<<dept<<" specialization are:"<<endl<<endl;
	
	int age,exp,count=0;
	string ID,fname,lname,ci,qua,spe;
	
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{
		if(spe==dept){
		cout<<"\t\t\t\t\t1.ID:"<<ID<<endl<<"\t\t\t\t\t2.First Name:"<<fname<<endl<<"\t\t\t\t\t3.Last Name:"<<lname<<endl<<"\t\t\t\t\t4.Age:"<<age<<endl<<"\t\t\t\t\t5.Qualification:"<<qua<<endl<<"\t\t\t\t\t6.Specialization:"<<spe<<endl<<"\t\t\t\t\t7.Experience:"<<exp<<endl<<"\t\t\t\t\t8.City:"<<ci<<endl<<endl;
		count++;
		}
	}

	fileObj.close();
	if(count==0){
		cout<<"\n\t\t\tNo doctors with this specialization found!"<<endl;
		getPatientDatabase();
	}
	else
		cout<<"\t\t\t\tNo of doctors with "<<dept<<" specialization:"<<count<<endl;

	cout<<"\n\n\t\t\t\tEnter 1 to return to Patient Database\n\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t\t\t=>";
	c= validate();
	if(c==1){
	  system("cls");
	  getPatientDatabase();	 //backtoPatientMenu
	}

	else
	  exit(0);
}

int addPat(){
	patient p;				//ID,firstname,lastname,age,phnumber,city,disease,Adate,Rdate,bill,spec
	    cout<<"\n\n\n\t\t\t\tFill up the following details"<<endl;
	    
	    cout<<"\n\t\t\t\tID: ";
	    p.p_ID = validate();
	    
   		cout<<"\t\t\t\tFirst Name: ";
   		cin>>p.fname;
   		
   		cout<<"\t\t\t\tLast Name: ";
   		cin>>p.lname;
   		
   		cout<<"\t\t\t\tAge: ";
   		p.p_age = validate();
   		
		cout<<"\t\t\t\tPhone No.: ";
   		cin>>p.phnumber;
   		
		cout<<"\t\t\t\tCity: ";
		cin>>p.p_city;
		
   		cout<<"\t\t\t\tDisease/Symptoms: ";
   		cin>>p.dis;
   		
   		cout<<"\t\t\t\tAdmission date  (DD/MM/YYYY): ";
   		cin>>p.addDate;
   		
   		cout<<"\t\t\t\tRelease date  (DD/MM/YYYY): ";
   		cin>>p.relDate;
   		
   		cout<<"\t\t\t\tTotal Bill generated: ";
   		p.bill = validate();
   		
		cout<<"\t\t\t\tKind of Specialization required: ";
		string dept=p.getDept();
		
		system("cls");
		
		fstream patObj;
		patObj.open("patient.txt");
		patObj<<p.p_ID<<endl<<p.fname<<endl<<p.lname<<endl<<p.p_age<<endl<<p.phnumber<<endl<<p.p_city<<endl<<p.dis<<endl<<p.addDate<<endl<<p.relDate<<endl<<p.bill<<endl<<dept<<endl;
		patObj.close();
		
	cout<<"\n\n\t\t\t\tNew Patient profile created successfully!"<<endl<<endl<<endl;
	cout<<"\n\n\t\t\t\tEnter 1 to return to Patient Database\n\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t\t=> ";
	c= validate();
	if(c==1){
	  system("cls");
	  getPatientDatabase();	 //backtoPatientMenu
	}
	else{
		cout<<"Exiting....\n";
		return 0;
	}
	  
}

void displayPat(){
	int x;
	
	cout<<"\n\n\n\n\t\t\tEnter the ID of the Patient whose profile you want to Display:"<<endl;
	cout<<"\n\t\t\t\t=> ";
	x= validate();
	
	fstream patObj("patient.txt");
	patObj.seekg(0);
	
	string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	double phnumber,bill;
	
	while(patObj>>p_ID>>fname>>lname>>p_age>>phnumber>>p_city>>dis>>addDate>>relDate>>bill>>dept)
	{
		if(p_ID==x){
		cout<<"\n\t\t\t\t\t1.ID: "<<p_ID<<endl<<"\t\t\t\t\t2.First Name: "<<fname<<endl<<"\t\t\t\t\t3.Last Name: "<<lname<<endl<<"\t\t\t\t\t4.Age: "<<p_age<<endl<<"\t\t\t\t\t5.Phone No.: "<<phnumber<<endl<<"\t\t\t\t\t6.City: "<<p_city<<endl<<"\t\t\t\t\t7.Disease/Symptoms: "<<dis<<endl<<"\t\t\t\t\t8.Admission date(DD/MM/YYYY): "<<addDate<<endl<<"\t\t\t\t\t9.Release date(DD/MM/YYYY): "<<relDate<<endl<<"\t\t\t\t\t10.Total Bill generated: "<<bill<<endl<<"\t\t\t\t\t11.Kind of Specialization required: "<<dept<<endl;
		count++;
		break;
		}
	}
	
	patObj.close();
	if(count==0){
		cout<<"\n\t\t\t\t\tNo matching records found!"<<endl;
		exit(0);
	}

	cout<<"\n\n\t\t\t\tEnter 1 to return to Patient Database\n\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t\t=> ";
	c= validate();
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}

	else
	  exit(0);
}

void dispPatDatabase(){
	fstream Obj("patient.txt");
	Obj.seekg(0);
	
	cout<<"\n\n\t\t\t\t\t\tPATIENT DATABASE"<<endl<<endl;
	
	string fname,lname,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	double phnumber,bill;
	
	while(Obj>>p_ID>>fname>>lname>>p_age>>phnumber>>p_city>>dis>>addDate>>relDate>>bill>>dept)
	{   
		count++;
		cout<<"\n\n\t\t\t\t\tPatient Profile:"<<count<<endl;
		cout<<"\t\t\t\t\t1.ID:"<<p_ID<<endl<<"\t\t\t\t\t2.First Name:"<<fname<<endl<<"\t\t\t\t\t3.Last Name:"<<lname<<endl<<"\t\t\t\t\t4.Age"<<p_age<<endl<<"\t\t\t\t\t5.Phone No.:"<<phnumber<<endl<<"\t\t\t\t\t6.City:"<<p_city<<endl<<"\t\t\t\t\t7.Disease/Symptoms:"<<dis<<endl<<"\t\t\t\t\t8.Admission date(DD/MM/YYYY):"<<addDate<<endl<<"\t\t\t\t\t9.Release date(DD/MM/YYYY):"<<relDate<<endl<<"\t\t\t\t\t10.Total Bill generated:"<<bill<<endl<<"\t\t\t\t\t11.Kind of Specialization required:"<<dept<<endl;
		}
	
	Obj.close();

	if(count==0){
		cout<<"\n\t\t\t\t\tNo matching records found!"<<endl;
		cout<<"\t\t\t\t\tEnter 1 to return to Patient Database\n\t\t\t\t\t2.Enter 2 to exit.";
		int c;
		if (c==1){
			system("cls");
	  		getPatientDatabase();
		}
	else
	  exit(0);		
	}

	cout<<"\n\n\t\t\t\t\tEnter 1 to return to Patient Database\n\t\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t\t=> ";
	c= validate();
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}

	else
	  exit(0);

}


void numberofPats(){
	fstream Obj("patient.txt");
	Obj.seekg(0);
	string fname,lname,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(Obj>>p_ID>>fname>>lname>>p_age>>phnumber>>p_city>>dis>>addDate>>relDate>>bill>>dept)
	{
	 count++;
	}

	Obj.close();
	cout<<"\n\n\t\t\t\tThe number of patients in the hospital are "<<count<<endl;

	cout<<"\n\n\t\t\t\tEnter 1 to return to Patient Database\n\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t\t=> ";
	c= validate();
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}



	else
	  exit(0);

}

int getStatus(){
 	bed b;
	cout<<"\n\n\n\n\n\t\t\t\t\tTotal Number of Beds in the hospital:"<<b.total<<endl;
	
	fstream file("patient.txt");
  	file.seekg(0);
	
	string fname,lname,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	
	double phnumber,bill;
	while(file>>p_ID>>fname>>lname>>p_age>>phnumber>>p_city>>dis>>addDate>>relDate>>bill>>dept)
	{
	 count++;
	}

	file.close();
	cout<<"\n\t\t\t\t\tThe number of Occupied Beds="<<count<<endl;
	cout<<"\n\t\t\t\t\tThe number of Empty Beds="<<b.total-count<<endl;

	cout<<"\n\n\t\t\t\t\tEnter 1 to return to Bed Database\n\t\t\t\t\tEnter 2 to Exit."<<endl;
	int c;
	cout<<"\n\t\t\t\t\t=>";
	c= validate();
	if(c==1){
	  system("cls");
	  getBedDatabase();
	}

	else
	  return 0;

}


int chooseMain(){

	int choice2;
	cout<<"\n\n\n\t\t\t\t\t\t MAIN MENU";
	cout<<"\n\t\t\t\t\t\t-----------"<<endl;
	cout<<"\t\t\t\t\t1.Enter Into Doctors' Database\n";
	cout<<"\t\t\t\t\t2.Enter Into Patients' Database\n";
	cout<<"\t\t\t\t\t3.Check for Hospital Bed Availability\n";
	cout<<"\t\t\t\t\t4.Exit";
	//cout<<"\n\t\t\t\t\t\t-----------"<<endl;

	cout<<"\n\n\t\t\t\t\t=> ";
	choice2= validate();
	while(choice2 < 1 || choice2 > 4){
		cout<<"\n\t\t\t\tError: Enter a valid option(1-4)=>";
		choice2= validate();
	}
	return choice2;
}


int getDoctorDatabase(){
	int choice_doc;
	cout<<"\n\n\n\n\n\t\t\t\t\tWELCOME TO DOCTOR'S DATABASE";
	cout<<"\n\t\t\t\t\t------------------------------";
	cout<<"\n\n\t\t\t\t\t1.Add New Doctor's Information";
	cout<<"\n\t\t\t\t\t2.Display a Doctor's Information";
	cout<<"\n\t\t\t\t\t3.Display Entire Doctor Database";
	cout<<"\n\t\t\t\t\t4.Total Number of Doctors";
	cout<<"\n\t\t\t\t\t5.Exit"<<endl;
	//cout<<"\n\t\t\t\t\t------------------------------";

	cout<<"\n\t\t\t\t\t=> ";
	
	choice_doc= validate();
	while(choice_doc < 1 || choice_doc > 5){
		cout<<"\n\t\t\t\t\tError: Enter a valid option(1-5)\n\t\t\t\t\t=>";

		choice_doc= validate();
	}
	system("cls");
	switch(choice_doc){
		case 1:{
//addDoc()
		    addDoc();
			break;
		}
		case 2:{
//displayDoc()
			displayDoc();
			break;
		}
		case 3:{
//dispDatabase()
			dispDatabase();
			break;
		}
		case 4:{
//numberOfDocs()
			numberofDocs();
			break;
		}

		case 5:{
			system("CLS");
			return 0;
		}
		default:{
			cout<<"\n\t\t\t\t\tEnter a valid option(1-5)\n";
		}
	}
}


int getPatientDatabase(){
	int choice_pat;
	cout<<"\n\n\n\n\t\t\t\t\tWelcome To Patient's Database";
	cout<<"\n\t\t\t\t\t------------------------------\n";
	cout<<"\n\t\t\t\t\t1.Add New Patient's Information"<<endl;
	cout<<"\t\t\t\t\t2.Display a Patient's Information"<<endl;
	cout<<"\t\t\t\t\t3.Display Entire Patient Database"<<endl;
	cout<<"\t\t\t\t\t4.Total Number of Patients"<<endl;
	cout<<"\t\t\t\t\t5.Check for doctor availability"<<endl;
	cout<<"\t\t\t\t\t6.Exit"<<endl;
	//cout<<"\t\t\t\t\t----------"<<endl;

	cout<<"\n\t\t\t\t\t=> ";
	choice_pat= validate();
	while(choice_pat < 1 || choice_pat > 6){
		cout<<"\n\t\t\t\t\tError: Enter a valid option(1-6)\n\t\t\t\t\t=>";
		choice_pat= validate();
	}
	system("cls");
	switch(choice_pat){
		case 1:{
//addPat()
		    addPat();
			break;
		}
		case 2:{
//displayPat()
			displayPat();
			break;
		}
		case 3:{
//dispPatDatabase()
			dispPatDatabase();
			break;
		}
		case 4:{
//numberOfPats()
			numberofPats();
			break;
		}
		case 5:{
//getDoctor
			getDoctor();
			break;
		}
		case 6:{
//exit
			system("CLS");
			return 0;
			break;
		}
		default:{
			cout<<"\n\t\t\t\t\tEnter a valid option(1-6)\n";
		}
	}
}

void getBedDatabase(){
int choice_bed;
	cout<<"\n\n\n\n\n\t\t\t\t\tWELCOME TO BED'S DATABASE";
	cout<<"\n\t\t\t\t\t1.Check Bed Status";
	cout<<"\n\t\t\t\t\t2.Exit";
	cout<<"\n\t\t\t\t\t----------"<<endl;

	cout<<"\n\t\t\t\t\t=> ";
	choice_bed= validate();
	while(choice_bed < 1 || choice_bed > 2){
		cout<<"\n\t\t\t\t\tError: Enter a valid option(1-2)\n\t\t\t\t\t=>";
		choice_bed= validate();
	}
	system("cls");
	switch(choice_bed)
	{
		case 1:{
//getStatus()
		    getStatus();
			break;
		}
		case 2:{
//exit
			exit(0);
			break;
		}
		default:{
			cout<<"\n\t\t\t\t\tEnter a valid option(1-2)";
		}
	}
}

int mainHospital(){
	system("color 0F");
	password A;
	
	system("cls");
//	cout<<"\n\n\n\n\n\t\t\t\t\t-------------------------\n";
//	cout<<"\t\t\t\t\tWelcome to Smart Hospital\n";
//	cout<<"\t\t\t\t\t-------------------------\n";
	cout<<"\t\t";
	printASCII();
	cout<<"\n\n\t\t\t\t\t1.Main Menu"<<endl;
	cout<<"\t\t\t\t\t2.Exit";
	cout<<"\n\t\t\t\t\t-----------------------\n";
	cout<<"\t\t\t\t\tEnter your choice:  ";
	int choice1;
	//cout<<"\t\t\t\t\t";
	choice1= validate();
	while(choice1 < 1 || choice1 > 2){
		cout<<"\n\t\t\t\t\tError: Enter a valid option(1-2)\n\t\t\t\t\t=>";
		cout<<"\t\t\t\t\t";
		choice1= validate();
	}
	if (choice1==1){
		 system("cls");
		 int var=chooseMain();
		 system("cls");

		 	switch(var){
			case 1:{
				A.passwordprotect();
				system("cls");
				getDoctorDatabase();
				break;
			}

			case 2:{
			    A.passwordprotect();
				system("cls");
				getPatientDatabase();
				break;

			}

			case 3:{
			    A.passwordprotect();
				system("cls");
				getBedDatabase();
				break;
			}

			case 4:
				{
				system("CLS");
				mainHospital();
				break;
				}
			default:
				cout<<"\n\t\t\t\t\tEnter a valid option."<<endl;
		}
	}
	else if(choice1==2){
		system("CLS");
		cout<<"\n\t\t\t\t\tExiting Hospital....\n";
		return 0;
	}
	else
	 cout<<"\n\t\t\t\t\t!Enter a valid option."<<endl;
	
	mainHospital();
}


void printASCII(){
	string line="";
	ifstream inFile;
	inFile.open("hospitalart.txt");
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
	cout<<"\t\t\t\t\tWelcome to Smart Hospital\n";
	cout<<"\t\t\t\t\t-------------------------\n";
	}
	inFile.close();
}


