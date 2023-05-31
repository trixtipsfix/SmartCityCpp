#include <iostream>

using namespace std;



class adminst {
		string name, name_s;
		int password_ad,regis_id; 
		char select,exit;
	public:
		int num,return_value,choice,val;
		adminst();
		int admin();
 		int new_student_info();
     	int student_info();
 		int admission_form();
 		int students_ofcyber();
		int daily_attendance();
};



class student: public adminst {
		int regis_id,choice;
		string n,name;
	public:
		int var,num,return_value,courses;
		student();
		int regis();
		int courses_information();
};



class faculty:public adminst  {
    	string  name;
    	int  password_fac,for_p,var2,choice,semester;
		string exam;
	public:
		int num; 
		faculty();
		int fun_faculty();
		int attendance();
		int adding_marks();
};



class new_user:public student{
	
       	public:
       		char ch;
       		string name;
       		int password,choice,num;
			int fun_newuser();
};	
int mainUniversity();
