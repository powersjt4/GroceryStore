/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 8/13/17
 ** Description: This is the produce department for
 ** for a series of derived classes for use in the
 ** Grocery class. This is all tied together in the
 ** Gameplay class that will create a grocery store
 ** exploration game.
 ********************************************
 *************************/
#include "Produce.hpp"
#include "Spaces.hpp"

Produce::Produce() : Spaces() {
	stockShelf();
}
/************************************************************
Produce::stockShelf()
Create all the items in the department and puts them in the
shelf vector.
***********************************************************/
void Produce::stockShelf() {
	shelf.push_back("Tomato");
	shelf.push_back("Potato");
	shelf.push_back("Onion");
	shelf.push_back("Cucumber");
	shelf.push_back("Lettuce");

}
/************************************************************
Produce::getDept()
Returns a map of the surrounding departments.
***********************************************************/
void Produce::getDept() {
	std::cout << "Your in the produce department\nWhich department would you like to go to next?" << std::endl;
	std::cout << "\t1: Wall ^\n\n2: <Wall \t4: Dairy > \n\n\t3: Entry v \n 0: exit" << std::endl;
}

/************************************************************
Produce::set*direction*()
These classes return a pointer to a department. It will be
linked differently for each department.
***********************************************************/
void Produce::setRight(Spaces &set) {
	right = &set;
}
void Produce::setBottom(Spaces &set) {
	bottom = &set;
}
/************************************************************
Produce::getDept()
Prints out a text file with a lower case name of the class
found in a containing text folder.
***********************************************************/
void Produce::getText() {
	std::string in;
	std::ifstream infile ("produce.txt");
	if (infile.is_open()) {
		while (getline(infile, in)) {
			std::cout << in << std::endl;
		}
		infile.close();
	} else {
		std::cout << "Cant open produce.txt" << std::endl;
	}
}


Produce::~Produce() {
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
}

