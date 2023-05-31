#include "University.h"
#include <iostream>
using namespace std;




int mainUniversity(){	
    int mode,return_value;
    student std;
	faculty fac;
	new_user newu;
	adminst admin;
	cout<<"\n \n   \t\t \t  Welcome To Air University "<<endl;
	cout<<"--------------------------------------------------------------------------------";
	cout<<"\n \n  \t  OUR UNI HAS PERFORMED VERY WELL IN THE RECENT DECADE \n \t AND IT STANDS ON 200 POSITION IN QEC WORLD RANKING ";	
	cout<<"\n\n------------------------------------------------------------------";
	cout<<"\n \n\t \t\t who are you  ";
	cout<<"\n-------------------------------------------------------------------";
	cout<<"\n\n\n \t 1.STUDENT \t 2.FACULTY \t 3.NEW USERS  \t4. ADMIN \n "; 
	cin>>mode;
	while( mode <1 || mode > 4 )	{
	  cout<<" \n SORRY! NO ABOVE OPTION MET\n ";
	  cin>>mode;	
	}
    
	switch(mode){
     	case 1:
     		return_value=std.regis();
     			
				 if(return_value == 0){
				 system("CLS");
				 	main();
				 }
				 break;
     	case 2:
     			return_value=fac.fun_faculty();
		if (return_value == 0){
	    	system("CLS");
			main();
		}
				 break;
     	case 3:
     		    return_value=newu.fun_newuser();
     	if (return_value == 0){
	    	system("CLS");
			main();
		}
		 	     break;
     	case 4:
     		
     			return_value=admin.admin();
     	if (return_value == 0){
	    	system("CLS");
			main();
		}
		 		break;
		 default:
     		cout<<" SOMETHING WENT WRONG ";			
	}
	return 0;
}
