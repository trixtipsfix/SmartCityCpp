#include <iostream>
using namespace std;

class product{
	int product_number;
	string product_name;
	float product_price,product_quantity,product_discount;
public: 
	void add_product();
	void show_all_product();
	void display_record(string prod_num);
	void place_order();
}; 

int mainMart();
void printAScii();
