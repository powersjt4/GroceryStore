/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 8/13/17
 ** Description: This is the Checkout department for
 ** for a series of derived classes for use in the
 ** Grocery class. This is all tied together in the
 ** Gameplay class that will create a grocery store
 ** exploration game.
 ********************************************
 *************************/
#include "Checkout.hpp"
#include "Spaces.hpp"

Checkout::Checkout() : Spaces() {
	stockShelf();
}

/************************************************************
Checkout::stockShelf()
Create all the items in the department and puts them in the
shelf vector.
***********************************************************/
void Checkout::stockShelf() {

}
/************************************************************
Checkout::getDept()
Returns a map of the surrounding departments.
***********************************************************/
void Checkout::getDept() {
	std::cout << "Your in the Checkout area\nWhich department would you like to go to next?" << std::endl;
	std::cout << "\t1: Bread ^\n\n2: <Meat \t4: Wall > \n\n\t3: wall v \n0: exit" << std::endl;
}
void Checkout::inspectShelves() {
	std::cout << "Just a bunch of checkout lines. You don't have all the items on your list. Press 0: ";
}

/************************************************************
Checkout::set*direction*()
These classes return a pointer to a department. It will be
linked differently for each department.
***********************************************************/
void Checkout::setTop(Spaces &set) {
	top = &set;
}
void Checkout::setLeft(Spaces &set) {
	left = &set;
}


void Checkout::getText() {
	std::string in;
	std::ifstream infile ("checkout.txt");
	if (infile.is_open()) {
		while (getline(infile, in)) {
			std::cout << in << std::endl;
		}
		infile.close();
	} else {
		std::cout << "Cant open checkout.txt" << std::endl;
	}
}
/************************************************************
Checkout::special()
This is a special event that happens in the Checkout department.
***********************************************************/
int Checkout::specialInt(int mod) {
	if (mod <= 0) {

		std::cout << "\nYou aren't ready to go to the checkout yet." << std::endl;
		std::cout << "***The people in the checkout eye you suspiciously.***\n" << std::endl;
		return 0;

	} else {
		std::cout << "Checkout 1: A tall brooding middle aged man." << std::endl;
		std::cout << "Checkout 2: A teenage kid making small talk." << std::endl;
		std::cout << "Checkout 3: For some reason the elderly person from the bread aisle?" << std::endl;
		std::cout << "Checkout 4: Express Lane -2 items or less" << std::endl;
		std::cout << "Which number checkout do you want to choose?\n" << std::endl;
		int in = 10;
		while (in > 0) {
			in = validate.checkValid(true, 1, 4);
			if (in == 1) {
				std::cout << "I think this guy hates his job (counter - 3) ." << std::endl;
				return in + 2;
			} else if (in == 2 ) {
				std::cout << "OH NO! Price check! (counter - 5)" << std::endl;
				return in + 3;
			} else if (in == 3) {
				std::cout << "This person is pretty fast at bagging groceries.(counter - 1)" << std::endl;
				return in - 2;
			} else {std::cout << "You have too many items to the express lane. Try another." << std::endl;}
		}//While
		return 0;
	}//else
}//specialInt();

Checkout::~Checkout() {
}

