#include "University.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include<limits>
#include<ctype.h>
using namespace std;


adminst::adminst(){
		name= "ALI";
		val=0;
}


int adminst::admin(){
          int count=0;
           
		system("CLS");
	cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";

		
	 cout<<"\n\n\t\t\t\t\t--------------------------------------\n \t";
	  cout<<"\t\t\t\t\tVALIDATION FOR ADMIN PORTAL\n ";
	  cout<<"\t\t\t\t\t--------------------------------------\n\n ";
	
		cin.ignore();
		cout<<" \n\t\t\t -> GIVE US YOUR NAME  \n\t\t\t  ";
		getline(cin,name);
		
	go:for(int i=0; i<name.length(); i++)
	{                                   // validation 
			if(isdigit(name[i]))
	{
    	  cout<<" \n\t\t \a ALERT! ONLY characters \n\n\t\t\t";
			
	      getline(cin,name);
		  goto go;    
	}
	
	
	}
		cout<<"\n\n\t\t\t ->GIVE US YOUR PASSWORD (only integers)";
	 there:
	 	cout<<"   \n\n\t\t\t  ";
		cin>>password_ad;
		
		 while(!cin)  // integer validation
    {            
    
	here:cout<<"\n\t\t\a ALERT! SELECT INTEGERS ONLY \n\t\t\t ";
 		
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 
	goto there;
		break;
	
	}
	
	if(name.length()==0){
		goto there;
	}
		
	come: ifstream file("password for admin.txt");
		int var;
		while(!file.eof())
		{
			file>>var;
		if(var == password_ad)
		{
			count++;
	jump:
	system("CLS");
	
	cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";

	cout<<"\n\n\t\t\t\t------------------------------------------------- ";
	cout<<"\n\t\t\t\t AIR UNIVERSITY ONLINE ASSISATNCE PROGRAM ";
	cout<<"\n\t\t\t\t--------------------------------------------------  \n"	;				
	cout<<" \n\n\t\t\tHOW CAN WE HELP YOU ";
	cout<<"\n\t\t\t-------------------------------\n";		
	cout<<"\n\t\t\t1. STUDENT INFORMATION  \n\n\t\t\t2. DAILY ATTENDANCE  \n\n\t\t\t3. STUDENTS OF CYBER \n\n\t\t\t4. ADMISSION FORM \n \n\t\t\t5. GO BACK 0\n ";
    cout<<"\n\n\t\t SELECT  ";
	cin>>choice;

   while(choice < 1 || choice > 5){
    cout<<"\n\n\t\t\a ALERT! ONLY BETWEEN 1  AND  5";
   	cin>>choice; 
   }
    if (choice == 1){
	return_value=student_info();
     if (return_value==0){
     	goto jump;
	 }
  }
	else if(choice == 2){
		return_value=daily_attendance();
        if (return_value==0){
        	goto jump;
		}
		}
    else if(choice == 3) { 
         return_value=students_ofcyber();
		 if (return_value==0){
		 goto jump;
		 }}
    else if (choice == 4){
	return_value=admission_form();
	if(return_value==0){
		goto jump;
	}
	 }
	 else if (choice == 5){
	 return val;	
	 }
	}
	file.close();
	
	if(count==0){
		cout<<"\n\t  WRONG PASSWORD \n\n\t \t";
       cout<<"->ENTER YOUR PASSWORD \n \t\t \n\t\t\t";
	    cin>>password_ad;
	    goto come;
        
		 }
	     }		
   }

int adminst::new_student_info(){
	string info;

	system("CLS");
     
    cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
    
	cout<<"\n\n\t\t\t\t\t------------------------------- ";
	cout<<"\n\t\t\t\t\t      ADMISSION INFORMATION  ";
	cout<<"\n\t\t\t\t\t-------------------------------\n ";
   	
    ifstream file ("details.txt");
	string data;
	
	while(!file.eof()){
		getline(file,data);
		cout<<data<<"\n";
	}

file.close();
}

int adminst::student_info(){

  int return_value;
    system("CLS");
    
    cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";

	cout<<"\n\t\t\t\t\t   ------------------------------- ";
	cout<<"\n\t\t\t\t\t      ADMISSION INFORMATION  ";
	cout<<"\n\t\t\t\t\t   -------------------------------\n ";

		cout<<" \n \n\t\t\t-> WHO YOU WANT TO ACCESS ?  \n\n\t\t\t  GIVE US HIS/HER  REGIS. ID:  ";
        
	jump:cin>>regis_id;
		  
		  while(!cin)  // integer validation
    {            
	here:cout<<"\n\t\t\t  ALERT! SELECT INTEGER ONLY \n\t\t\t";
 		
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 
	goto jump;
		break;
	}
		
		while(regis_id<21100||regis_id>21160){
			
		cout<<"\n\n\t\t\t  ONLY BETWEEN  21100  AND  211060 \n\n\t\t\t";
		cin>>regis_id;	
		
		}
		  
	  
       cout<<"\n\n\t\t\t  ----------------------------------------------------\n";
	   	    
		ifstream read("ids of cyber.txt");
	   		    string var3;
		  
		  while(!read.eof()){
	   	  
			 read>>var3;
	   	 if(var3==to_string(regis_id))
		{
			ifstream file ("details.txt");
			string data;
	    
	    while(!file.eof()){
		
		getline(file,data);
		cout<<"\t\t\t\t  "<<data<<"\n";  
       }
       file.close();
	   }

	 }
	read.close();
	   
	cout<<"\t\t\t  ----------------------------------------------------- \n ";  
	  
     cout<<"\t\t\t  GO BACK (0) ->"; 	
     cin>>return_value;
     if (return_value == 0){
     	return return_value;
	 }
}


int adminst::admission_form(){
 	char ch;
 	int exit;
	 system("CLS");
 	cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";

	cout<<"\n\t\t\t\t\t------------------------------- ";
	cout<<"\n\t\t\t\t\t      ADMISSION INFORMATION  ";
	cout<<"\n\t\t\t\t\t-------------------------------\n ";

    ifstream read("admission form.txt");
    string info;
    while(!read.eof()){
    	getline(read,info);
    	cout<<"\t"<<info<<"\n";
}
  read.close(); 
  cout<<"\t\t\t--------------------------------------------------- \n";
  cout<<"\t\t\t  DO YOU WANT TO PRINT THE FORM \n";

 cout<<" \n\t\t\t  DO YOU WANT TO FILL THE FORM  ONLINE  (y/n)? \n\t\t\t  ";
 cin>>ch;
 if ((ch=='y')||(ch=='Y')){
 	system("CLS");
 	
	cout<<"\n\t\t\t\t------------------------------- ";
	cout<<"\n\t\t\t\t\t      ADMISSION INFORMATION  ";
	cout<<"\n\t\t\t\t-------------------------------\n\n  ";
	
ifstream file("admission form cy.txt");
ofstream read("form.txt",std::ofstream::trunc);
string val,fill;
while(!file.eof())
{
 getline(file,val);
 cout<<"\t \n"<<val;
cin.ignore();
 getline(cin,fill);
 read<<val<<"  "<<fill<<" \n ";
 }
 read.close();
 file.close();
 cout<<"\n\n----------------------------------------------------\n\t -> exit 0 ";
 cin>>exit;
 if (exit ==0){
 	return 0;
 }
}
 else if (ch=='n'||ch=='N'){	
 		return 0;
  }
}

 
int adminst::students_ofcyber(){ /////
 	
 	int num;
 	
 	system("CLS");
 	
    cout<<"\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------";
     cout<<"\n\n\t\t\t\t\t     -------------------------";
     cout<<" \n\t\t\t\t\t        STUDENT OF CYBER ";
 	cout<<"\n\t\t\t\t\t     ---------------------------";
 	cout<<" \n\n ";
 	ifstream file("student_names.txt ");
 	string names;
 	while(!file.eof()){
 	cout<<" \t ";
 	getline(file, names);
 	cout<<"\t"<<names<<"\n";
	}
	file.close();
	 cout<<"\n\n\t\t\t------------------------------------------------------\n\t\t\t  GO BACK (0) ->";
	 cin>>num;
	 if (num==0){
	 	return num;
	 }
	}
	 
	 
int adminst::daily_attendance(){  // 
    int num;
    
   system("CLS");
    cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
               
    ifstream file("attendance.txt");
    string var;
  while(!file.eof()){

	getline(file,var);
	cout<<var<<"\n";
  
  }
	file.close();
	
	cout<<"\n\n\t\t\t\t  -----------------------------------------------\n\n";
	
	cout<<"\t\t\t  GO BACK (0) ->";
	cin>>num;
	while(num!=0){
		cout<<"\t\t\t  ";
		cin>>num;
	}
	if(num==0){
		return 0;
	} 
  }


student::student(){
		   
			regis_id = 0000;
			name = "ALI";
		}
		
		
int student::regis(){
	
	
	system("CLS");
	cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
	 cout<<"\n\n\t\t\t\t\t--------------------------------------\n \t";
	  cout<<"\t\t\t\t     VALIDATION FOR STUDENT PORTAL ";
	  cout<<"\n\t\t\t\t\t--------------------------------------";
	
	cin.ignore();
	cout<<" \n\n\n\t\t\t  ->YOUR NAME : ";
	jump3:cout;
    getline(cin,name);
    
	for( int i=0; i<name.length(); i++ ){ // string validation 
	    if(isdigit(name[i])){
	    	cout<<" \n\t\t\t \a ALERT! ONLY characters \n\t\t \t ";
		    getline(cin,name);
		}
    }
    
	while(name.length()==0){
	    cout<<"\n\t\t\t  MUST ENTER YOUR NAME ";
		goto jump3;
	}
	
    cout<<"\n\t\t\t  ->ENTER YOUR REGISTATION ID: ";
   	there:
    cin>>regis_id;
    while(!cin)  {    // integer validation
	here:
		cout<<"\n\t\t\t  ALERT! SELECT INTEGERS ONLY \n\t \t\t ";
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 
		goto there;
		break;
	}
	
   	while ( regis_id <= 21100 || regis_id >= 21160 )	{
	
	cout<<"\n\t\tERROR:ONLY BETWEEN 21100 TO 21160\n\t\t=>";
	cin>>regis_id;	
	
	while(!cin){
		goto here;
	}  
	}
	
    ifstream textfile;
	textfile.open("ids of cyber.txt"); // file handling 
	string var = "0";

	while(getline(textfile, var)){
		
	if( var == to_string(regis_id) ){

	movehere: 
		system("CLS");
		cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	    cout<<" \n\n\t\t\t\t\t--------- STUDENT PORTAL----------";	
	    cout<<"\n\n\t\t\t  ->1. DETAILS OF ADMISSIONS \n\t\t\t  ->2. DAILY ATTENDANCE \n\t\t\t  ->3. COURSES YOU SELECTED  \n\t\t\t  ->4. MARKS \n\t\t\t  ->5. GO BACK";
	jump:cout<<"\n\t\t\t  "; 
	cin>>choice;  
     
    while(!cin)  // integer validation
    	{            
	jump2:cout<<"\n\t\t\t  ALERT! SELECT INTEGER ONLY \n\t\t \t ";
 		
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 
	goto jump;
		break;
	}
	
  while(choice<1 ||choice > 5)
  {
  	cout<<"\t\t\t  ";
  	cin>>choice;
  	while(!cin){
  		goto jump2;
	 }
  }
   if (choice==1){

	return_value=student_info();
         if(return_value==0){
         	goto movehere;
		 }
} 
   else if(choice==2){
    return_value =daily_attendance();
    if(return_value == 0){
          goto movehere;
	} 
   }
   else if(choice==3){
   	return_value=courses_information();
   	if (return_value==0){
   		goto movehere;
	   }
   }
   
    else if (choice==4){
    
	  system("CLS");
    cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";   
    cout<<" \n\t\t\t\t\t--------- STUDENT PORTAL----------\n\n ";	
	cout<<"\n\t\t\t\tReg. ID\tOOP\tOOP-L\tDS\tISE\tSIA\n";
    	ifstream file("marks.txt");
    	string val;
    	
    	while(getline(file,val)){
    		cout<<"\n\t\t\t\t";
    		for (int i = 0 ; i < val.length() ; i++){
    			if (val[i] == ' '){
    				cout<<'\t';
				}
				else{
					cout<<val[i];
				}
			}
		}
		file.close();
		cout<<"\n\n \t\t\t ---------------------------------------------------------\n \t";
		cout<<"\t\t\t\t GO BACK (0) ->";
		cin>>num;
		if (num==0){
			goto movehere;
		}
	}
	else if (choice == 5){
		return 0;
	}
	
	break;
	}
}
	textfile.close();
	
}


int student::courses_information(){
	int num;
	
	system("CLS");
	
    cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
    
    
	cout<<"\n\n\t\t\t  WHICH SEMESTER DO YOU WANT TO KNOW \n";
	cout<<"\t\t\t  -------------------------------------------- \n\t\t\t  ";
there:cin>>courses;
	
	 while(!cin)  // integer validation
    {            
    
	here:cout<<"\n\t\t\t ALERT! SELECT INTEGERS ONLY \n\t\t\t   ";
 		
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 
	goto there;
		break;
	
	}
	
	while(courses<1||courses>3){
		cout<<"\t\t\t  ";
		cin>>courses;
	while(!cin)  // integer validation
    {            
    goto here;	
	}
     }
	if(courses==1 ) {
		
	cout<<"\n\n\t\t\t\t AIR UNIVERSIYY PROVIDES FOLLOWING COURSES TO CYBER STUDENTS\n";
	cout<<"\n\t\t\t\t------------------------------------------------------------\n";
	ifstream file("courses1.txt");
   string var;
 while(getline(file,var)){
 	cout<<"\t\t\t\t";
 	cout<<var;
 	cout<<endl;
 }
 file.close();
}
 else if (courses==2){
 	cout<<"\n\n\t\t\t\t AIR UNIVERSIYY PROVIDES FOLLOWING COURSES TO CYBER STUDENTS\n";
    cout<<"\n\t\t\t\t------------------------------------------------------------\n";
	ifstream file("courses2.txt");
   string var;
 while(getline(file,var)){
 	cout<<"\t\t\t\t";
 	cout<<var;
 	cout<<endl;
 }
 file.close();
 	
 }
 else if (courses==3){
 	cout<<"\n\n\t\t\t\t AIR UNIVERSIYY PROVIDES FOLLOWING COURSES TO CYBER STUDENTS\n";
	cout<<"\n\t\t\t\t------------------------------------------------------------\n";
	ifstream file("courses3.txt");
   string var;
 while(getline(file,var)){
 	cout<<"\t\t\t\t";
 	cout<<var;
 	cout<<endl;
 }
 file.close();	
 }
 cout<<"\t\t\t\t---------------------------------------------------\n ";
 
 cout<<"\t\t\t  GO BACK (0) ->";
 cin>>num;
 
 while(num!=0){
 
 cin>>num;
}
 if(num==0){
 
 return 0;
}
}



faculty::faculty(){
    	name="ali";
    	password_fac=00;
		num=0;
}

int faculty::fun_faculty(){
	
	int val;
	int count=0;
	system("CLS");
	cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
	cout<<"\n\t\t\t\t\t---------------------------------------\n";
	cout<<"\t\t\t\t\tONLINE ASSITANCE PLATFORM FOR FACULTY \n";
    cout<<"\t\t\t\t\t--------------------------------------- \n";		
		cin.ignore();
		cout<<" \n\n\n\t\t\t->ENTER YOUR NAME \n\t\t\t  ";
  jump:getline(cin,name);
		 
     	for( int i=0; i<name.length(); i++ ){ // string validation 
	
      if(isdigit(name[i])){
        	cout<<" \n\t\t\t\a ALERT! ONLY characters \n\t\t\t   ";
	        getline(cin,name);
	     }
           }
		            
	while(name.length()==0){
	    cout<<"\n\t\t\t\a ->MUST ENTER YOUR NAME \n \t \t\t ";
		goto jump;
	}
		
		cout<<"\n\t\t\t->ENTER YOUR PASSWORD  (only integers)";
	climb: cout<<" \t\t \n\t\t\t";  
	  cin>>password_fac;
	
		while(!cin)  // integer validation
	 {  
	  cout<<"\n\n\t\t\a ALERT! SELECT INTEGER ONLY \n  ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 
		goto climb;
		break;
	}
		
	there:ifstream file("password for faculty.txt");
		int var;
		
		while(!file.eof()){
			file>>var;	  	
	if ( password_fac == var ){
		count++;
	here:system("CLS");
    
    cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
	cout<<"\n\t\t\t\t\t--------------------------------------\n";
	cout<<"\t\t\t\t\tONLINE ASSITANCE PLATFORM FOR FACULTY \n";
    cout<<"\t\t\t\t\t-------------------------------------- \n";		
    
	cout<<"\n\n\t\t\t--------------------------------------------------------------------- ";
	cout<<"\n\n\t\t\t 1. ATTENDANCE   2. MARKS   3. STUDENTS OF CYBER   4.  GO BACK  \n";
	cout<<"\n\t\t\t--------------------------------------------------------------------- ";
    come:cout<<"\n\n\t\t\t\t Select: ";
	cin>>choice;	
	
	while(!cin){
	cout<<"\n\n\t\t\tONLY INTEGER: ";	
     cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(),'\n');
     goto come;
     break;
	}
	
	while( choice<1 || choice>4 ){
     cout<<"\n\n\t\t\t Select: "; 
	cin>>choice;
	
	}
	break;
	}
   }
      file.close();
      
	 if (count==0){
	   cout<<"\n\t\t\tWRONG PASSWORD \n\n\t\t\t";
       cout<<"->ENTER YOUR PASSWORD \n \t\t \n\t\t\t";
	    cin>>password_fac;
	    goto there;
         }
    	
		switch (choice){
    	case 1:
    			val=attendance();
            if (val==0){
            	goto here;
			}			
			   break;
		case 2:
			val=adding_marks();
		  if (val==0){
		  	goto here;
		  }
		  break;	
		case 3:
				val=students_ofcyber();
				if (val==0){
					goto here;
				}
				break;
		case 4: 
				return num;
				break;      		
}}



int faculty::attendance(){
int choice ,num;
system("CLS");
    cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
	cout<<"\n\t\t\t\t\t---------------------------------------\n";
	cout<<"\t\t\t\t\tONLINE ASSITANCE PLATFORM FOR FACULTY \n";
    cout<<"\t\t\t\t\t--------------------------------------- \n";		
	

 cout<<"\n \n\t\t\t\t\t      \tATTENDANCE PAGE ";
 cout<<"\n\t\t\t\t\t------------------------------------";
 cout<<"\n\n\t\t\t\t\t      ------SELECT CLASS------- ";
 cout<<"\n\n\t\t\t->CYBER 1ST SEMESTER \n\n\t\t\t->CYBER 2ND SEMESTER \n\n\t\t\t->CYBER 3RD SEMESTER \n\n\t\t\t->CYBER 4TH SEMESTER ";	
come:cout<<" \n\n\t\t\t SELECT ";
 cin>>choice;	
   	
	while(!cin){
	climb:cout<<"\n\n\t\t ONLY INTEGER: ";	
     cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(),'\n');
     goto come;
     break;
	}
  
 while(choice<1||choice>4){
	cout<<" \n\t\t\t SELECT. ";
	cin>>choice;
	while(!cin){
		goto climb;
	}
 }
 if ((choice==1||choice==2)||(choice==3||choice==4)){
 system("CLS");

    cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
	cout<<"\n\t\t\t\t\t---------------------------------------\n";
	cout<<"\t\t\t\t\tONLINE ASSITANCE PLATFORM FOR FACULTY \n";
    cout<<"\t\t\t\t\t--------------------------------------- \n";		
	

 cout<<"\n\t\t\t\t\t          ATTENDANCE PAGE ";
 cout<<"\n\t\t\t\t\t  ------------------------------------ \n \n ";

 cout<<"\n\t\t\tROLL. NO     ABSENT/PRESENT\n ";
 ifstream file("ids.txt");
 ofstream read;

 int id; 
 char ch;
 while(!file.eof())
 { 
	file>>id;
	cout<<"\t\t\t"<<id<<"\t\t\t";
	cin>>ch;
	//cout<<"\n ";
	read<<id<<" "<<ch<<"\n";
 }
 file.close();
 read.close();
 }
 cout<<"\n\t\t\t -------------------------------------------------------------\n";
 cout<<"\t\t\t  GO BACK (0) ->";
 cin>>num;
 if(num==0){
	return 0;
 }
 }


int faculty::adding_marks(){
	system("CLS");
	cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
	cout<<"\n\t\t\t\t\t---------------------------------------\n";
	cout<<"\t\t\t\t\tONLINE ASSITANCE PLATFORM FOR FACULTY \n";
    cout<<"\t\t\t\t\t--------------------------------------- \n";		
	
	cout<<" \n\t\t\t\t\t         PORTAL FOR ADDING MARKS \n";
	cout<<"\t\t\t\t\t    -----------------------------\n\n ";
	cout<<" \n\t\t\t ->SELECT SEMESTER OF CYBER SECURITY STUDENTS ";
come:cout<<"\n\n\t\t\t  Select. ";
	
	cin>>semester;
	
	while(!cin){
	climb:cout<<"\n\n\t\t\t  ONLY INTEGER: \n";	
     cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(),'\n');
     goto come;
     break;
	}
	
	while(semester<1||semester>4){
	cout<<"\n\n\t\t\t  Select. ";
	cin>>semester;	
	while(!cin){
	goto climb;	
	}
	
	}
	cout<<"\n\n \t\t\t  MIDS EXAM\t  FINAL EXAMS \n\n \t\t\t  Select.";
	cin>>exam;
    cout<<endl<<endl<<endl;
    system("CLS");
	
	cout<<"\n\t\t\t\t\t---------------------------------------\n";
	cout<<"\t\t\t\t\tONLINE ASSITANCE PLATFORM FOR FACULTY \n";
    cout<<"\t\t\t\t\t--------------------------------------- \n";		
	
	cout<<" \n\t\t\t\t\t        PORTAL FOR ADDING MARKS \n";
	cout<<"\t\t\t\t\t       -----------------------------\n\n ";
	
	cout<<"\t\tREGIS. IDS \t SUBJECTS\n\n ";
	 cout<<"\t\t\t CYBER SECUITY  DISCRETE  INFORMATION ASSURANCE  OOPS  OOP LAB \n ";
	
	ifstream file("ids.txt");
	ofstream read; 
	read.open("marks.txt",std::ofstream::trunc);
    int id; 
   int marks[5];
  while(!file.eof())
  {
  	cout<<"\t\t";
	file>>id;
	cout<<id<<"\t\t ";
	cin>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4];
	cout<<"\n ";    
	read<<id<<" "<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<" "<<marks[3]<<" "<<marks[4]<<"\n";   
  }
     read.close();
     file.close();
	cout<<"\n\t\t\t ---------------------------------------------------- \n";
    cout<<"\t\t\t  GO BACK (0) ->";
    cin>>num;
    if(num==0){
	return num;
  }
  }


int new_user::fun_newuser(){
	here:		
		system("CLS");
		num=0;
		cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	    cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	    cout<<"\t\t\t  -------------------------------------------------------------------\n";
		
		cout<<"\n\n\t\t\t\t---------------------------------------------------  ";
		cout<<" \n\t\t\t\t WELCOME TO AIR UNIVERSITY ONLINE ASSISTANCE PROGRAM \n";
    	cout<<"\t\t\t\t-----------------------------------------------------\n";
     	cout<<"\n\n\t\t\t\t THE UNIVERSITY HAS MANY FACILITIES AND LABS \n \t\t\t\t";
    	cout<<" THE ADMISSION FOR CYBER DEPARTMENT ARE OPEN  \n";
    cout<<"\n\n\t\t\t --------------------------------------------------------------------------";
		cout<<"\n\t\t\t1. COURSES FOR CYBER SECURITY    2.  ADMISSION FORM   3. GO BACK ";
    cout<<"\n\t\t\t ---------------------------------------------------------------------------\n";

        fly:cout<<"\n\t\t\t Select. ";
     	cin>>choice;
       
       while(!cin)  // integer validation
	{  
	
	come:cout<<"\n\n\t\t\t\a ALERT! SELECT INTEGER ONLY  \n ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 
		goto fly;
		break;
	}

	while(choice<1||choice>3){
		cout<<"\n\n\t\t\t Select. ";
		cin>>choice;
	while(!cin){
		goto come;
	}
	
	}
	    switch (choice){
	    	
		case 1:
		       num=courses_information();
		       if (num==0){
		       	goto here;
			   }
			   break;
		case 2:
			   num=admission_form();
			   if(num==0){
			   	goto here;
			   }  
		case 3:
			return num;
			 break;
	default:
	        	cout<<"\n\t\t SOMETHING WENT WRONG ";
	        	goto here;
  }
   }

int mainUniversity(){	
system("color F5");

    int mode,return_value;
    student std;
	faculty fac;
	new_user newu;
	adminst admin;
	system("CLS");
	cout<<"\n\n\n\t\t\t  -------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t      Welcome To Air University \t\t\t"<<endl;
	cout<<"\t\t\t  -------------------------------------------------------------------\n";
	
	cout<<"\n\t\t\t\t  OUR UNIVERSITY HAS PERFORMED VERY WELL IN THE RECENT DECADE \n\n\t\t\t\t\t\t\tAND \n\n\t\t\t\t     IT STANDS ON 200 POSITION IN QEC WORLD RANKING \n";	
	cout<<"\n\n\t\t\t\t\t     ------------------------";
	cout<<"\n\t\t\t\t\t\t   who are you   \n";
	cout<<"\t\t\t\t\t     ------------------------";
	cout<<"\n\n\t\t\t----------------------------------------------------------";
	cout<<"\n\n\t\t\t1. STUDENT \n\t\t\t2. FACULTY \n\t\t\t3. NEW USERS  \n\t\t\t4. ADMIN \n\t\t\t5. Exit ";
	cout<<"\n\t\t\t-----------------------------------------------------------"; 
there:cout<<"\n\t\t\tSelect  ";
    cin>>mode;
	
	while(!cin)  // integer validation
	{  
	
	here:cout<<"\n\t\t\tALERT! SELECT INTEGER ONLY   ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 
		goto there;
		break;
	}
		while( mode <1 || mode > 5 )	{
	  cout<<" \n\t\t\tALERT! NO ABOVE OPTION MET\n\t\t\tSelect ";
	  cin>>mode;
	  while(!cin){
	  	goto here;  // goes to integer validation
	  }
	}
    
	switch(mode){
     	case 1:
     		return_value=std.regis();
     			
				 if(return_value == 0){
				 system("CLS");
				 	mainUniversity();
				 }
				 break;
     	case 2:
     			return_value=fac.fun_faculty();
		if (return_value == 0){
	    	system("CLS");
			mainUniversity();
		}
				 break;
     	case 3:
     		    return_value=newu.fun_newuser();
     	if (return_value == 0){
	    	system("CLS");
			mainUniversity();
		}
		 	     break;
     	case 4:
     		
     			return_value=admin.admin();
     	if (return_value == 0){
	    	system("CLS");
			mainUniversity();
		}
		 		break;
		case 5:
			system("CLS");
			cout<<"\n\t\t\t\t\tExiting University...\n\n";
			break;
		 default:
     		cout<<"\t\t\t SOMETHING WENT WRONG ";			
	}
	
	
}
