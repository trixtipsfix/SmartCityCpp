#include <iostream>
using namespace std;

int chooseMain();
int getDoctorDatabase();
int getPatientDatabase();
void getPatientReport();
void getBedDatabase();
int mainHospital();

void printASCII();

class password{				//password class
	public:
		string x;
		int passwordprotect();
};


class doctor{							//doctor class
public:
	string d_fname,d_lname;
	int d_ID, d_age,experience,d_totalno;
	string qual,d_city;
	string getSpec();
   	friend void addDoc();
   	friend int displayDoc();
   	friend int dispDatabase();
   	friend void numberofDocs();
   	friend int getDoctorDatabase();
};

class patient{
public:
	
	string fname,lname,p_city,dis,addDate,relDate;
	int p_age,p_ID;
	long int bill;
	string phnumber;
	string getDept();
	friend void getDoctor();
	friend int addPat();
	friend void displayPat();
	friend void dispPatDatabase();
	friend void numberofPats();
   	friend int getPatientDatabase();
};

class bed{
	public:
	int total=1000;
	friend int getStatus();
};
